# ответ Алисы
# Определяем словарь соответствия входных и выходных слов
word_mapping = {
    "VETER": "TEPLO",
    "SOPLO": "SALKI",
    "KOREN": "PLUTO",
    "YASLI": "SONIK"
}

# Функция для анализа входного слова и возврата соответствующего выходного слова
def analyze_word(input_word):
    return word_mapping.get(input_word, "Unknown")

# Пример использования функции
input_words = ["VETER", "SOPLO", "KOREN", "YASLI"]
for word in input_words:
    output_word = analyze_word(word)
    print(f"Входное слово: {word}, выходное слово: {output_word}")
