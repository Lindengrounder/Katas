#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// --- Structure to hold response data from the web request ---
struct string {
    char *ptr;
    size_t len;
};

// --- Callback function to write data received by libcurl ---
static size_t write_callback(void *contents, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "ERROR: memory allocation failed in write_callback\n");
        return 0;
    }
    memcpy(s->ptr + s->len, contents, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;
    return size * nmemb;
}

// --- Function to get the response from the translation API ---
char *translate_text(const char *text, const char *target_lang) {
    CURL *curl;
    CURLcode res;
    struct string response;
    response.ptr = malloc(1);
    response.len = 0;
    response.ptr[0] = '\0';

    char *url = NULL;
    char *escaped_text = NULL;
    char *final_text = NULL;

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "ERROR: Could not initialize libcurl\n");
        goto cleanup;
    }

    // URL encode the text to be safe
    escaped_text = curl_easy_escape(curl, text, 0);
    if (!escaped_text) {
        fprintf(stderr, "ERROR: Could not URL-encode the text\n");
        goto cleanup;
    }

    // Construct the full URL for the Lingva API request
    // We're using the 'auto' source language detection for simplicity
    int url_len = snprintf(NULL, 0, "https://lingva.ml/api/v1/auto/%s/%s", target_lang, escaped_text) + 1;
    url = malloc(url_len);
    if (!url) {
        fprintf(stderr, "ERROR: Memory allocation failed for URL\n");
        goto cleanup;
    }
    snprintf(url, url_len, "https://lingva.ml/api/v1/auto/%s/%s", target_lang, escaped_text);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "DayToday-CLI/1.0");

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "ERROR: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        goto cleanup;
    }

    // Simple JSON parsing to extract the translation
    // We're looking for: "translation":"..."
    char *json_start = response.ptr;
    char *trans_key = "\"translation\":\"";
    char *trans_start = strstr(json_start, trans_key);
    if (trans_start) {
        trans_start += strlen(trans_key);
        char *trans_end = strchr(trans_start, '\"');
        if (trans_end) {
            size_t trans_len = trans_end - trans_start;
            final_text = malloc(trans_len + 1);
            if (final_text) {
                strncpy(final_text, trans_start, trans_len);
                final_text[trans_len] = '\0';
            }
        }
    }

    if (!final_text) {
        fprintf(stderr, "WARNING: Could not parse translation from API response\n");
        final_text = strdup(text);  // fallback to original text
    }

cleanup:
    if (escaped_text) curl_free(escaped_text);
    if (url) free(url);
    if (response.ptr) free(response.ptr);
    if (curl) curl_easy_cleanup(curl);
    return final_text;
}

// --- Function to get the current date and calculate the day number ---
int get_day_of_year(int *year, int *month, int *day) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    *year = tm_info->tm_year + 1900;
    *month = tm_info->tm_mon + 1;
    *day = tm_info->tm_mday;
    return tm_info->tm_yday + 1;  // tm_yday is 0-indexed
}

// --- Helper function to map language codes to full names ---
const char* get_language_name(const char *code) {
    if (strcmp(code, "en") == 0) return "English";
    if (strcmp(code, "es") == 0) return "Spanish";
    if (strcmp(code, "fr") == 0) return "French";
    if (strcmp(code, "de") == 0) return "German";
    if (strcmp(code, "it") == 0) return "Italian";
    if (strcmp(code, "pt") == 0) return "Portuguese";
    if (strcmp(code, "ru") == 0) return "Russian";
    if (strcmp(code, "ja") == 0) return "Japanese";
    if (strcmp(code, "ko") == 0) return "Korean";
    if (strcmp(code, "zh") == 0) return "Chinese";
    if (strcmp(code, "ar") == 0) return "Arabic";
    if (strcmp(code, "hi") == 0) return "Hindi";
    return code;
}

int main(int argc, char *argv[]) {
    int year, month, day;
    int day_of_year = get_day_of_year(&year, &month, &day);
    
    // Create the base message
    char base_message[256];
    snprintf(base_message, sizeof(base_message), 
             "Today is %d-%02d-%02d, the %d%s day of the year %d.",
             year, month, day, day_of_year, 
             (day_of_year % 10 == 1 && day_of_year != 11) ? "st" :
             (day_of_year % 10 == 2 && day_of_year != 12) ? "nd" :
             (day_of_year % 10 == 3 && day_of_year != 13) ? "rd" : "th",
             year);
    
    // Check if a language code was provided as a command-line argument
    if (argc > 1) {
        char *target_lang = argv[1];
        char *translated_message = translate_text(base_message, target_lang);
        if (translated_message) {
            printf("%s (translated to %s)\n", translated_message, get_language_name(target_lang));
            free(translated_message);
        } else {
            printf("%s (Translation failed, showing original)\n", base_message);
        }
    } else {
        // No language specified, just output in English
        printf("%s\n", base_message);
        printf("\nUsage: %s <language_code>\n", argv[0]);
        printf("Example: %s es  (for Spanish)\n", argv[0]);
        printf("Supported languages: en, es, fr, de, it, pt, ru, ja, ko, zh, ar, hi\n");
    }
    
    return 0;
}