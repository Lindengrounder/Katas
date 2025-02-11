#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char username[50];

void printDelay(const char* msg, unsigned delay) {
    printf("%s", msg);
    usleep(delay);
}

void showMessages(const char* title, const char* lines[], int count, unsigned delay) {
    printDelay(title, delay);
    for(int i = 0; i < count; i++) 
        printDelay(lines[i], delay);
    putchar('\n');
}

void getUserName() {
    const char* prompts[] = {
        "Введите ваше имя: ",
        "\nПривет, %s! Добро пожаловать в JDoodle!\n"
    };
    
    printf("%s", prompts[0]);
    scanf("%49s", username);
    printf(prompts[1], username);
    usleep(500000);
}

void showHeader() {
    const char* lines[] = {
        "============================================\n",
        "            \U0001F680 Добро пожаловать в JDoodle!           \n",
        "============================================\n\n"
    };
    showMessages("", lines, 3, 500000);
}

void showSection(const char* emoji, const char* title, const char* items[], int count) {
    char header[100];
    sprintf(header, "%s %s, %s!\n", emoji, title, username);
    
    const char* content[count+1];
    content[0] = header;
    for(int i = 0; i < count; i++) content[i+1] = items[i];
    
    showMessages("", content, count+1, 500000);
}

void showRandomTip() {
    const char* tips[] = {
        "Используйте комментарии для пояснения кода!",
        "Регулярно сохраняйте свои проекты!",
        "Пробуйте разные языки программирования!",
        "Делитесь кодом с друзьями!",
        "Изучайте новые алгоритмы и структуры данных!"
    };
    printf("\n\U0001F4DA Полезный совет: %s\n\n", tips[rand()%5]);
    usleep(500000);
}

void showTryItNow() {
    printDelay("\n\U0001F680 Попробуйте запустить код прямо сейчас!\n", 500000);
    printf("Введите простую команду на Python (например, print(\"Hello, World!\")): ");
    
    char code[100];
    scanf(" %99[^\n]", code);
    printf("\nВы ввели: %s\n", code);
    printDelay("Представьте, что ваш код сейчас выполняется... \U0001F916\n\n", 2000000);
}

void showMenu() {
    const char* menu[] = {
        "1. Приветствие \n", "2. Основные возможности \n", "3. Как начать \n",
        "4. Полезные функции \n", "5. Дополнительные возможности \n", 
        "6. Случайный совет \n", "7. Выполнить код \n", "8. Заключение \n", "0. Выход \n"
    };
    
    void (*functions[])() = {
        [1] = showHeader, [2] = showSection, [3] = showSection, 
        [4] = showSection, [5] = showSection, [6] = showRandomTip,
        [7] = showTryItNow, [8] = showHeader
    };
    
    const char* sectionParams[][4] = {
        {"\U0001F4CC","Используйте JDoodle", (char*[]){
            "   - Запускайте код на 88 языках программирования!\n",
            "   - Работайте в среде Python3 по умолчанию!\n", NULL}, "2"},
        {"\U0001F4DD","Следуйте инструкциям", (char*[]){
            "   1. Нажмите 'Execute' \u25B6 для запуска кода!\n",
            "   2. Изменяйте код прямо в редакторе!\n", NULL}, "2"},
        {"\U0001F4A1","Используйте инструменты", (char*[]){
            "   \u2192 Обратитесь к JDroid \u27A1 для помощи в написании и отладке кода!\n",
            "   \u2192 Открывайте меню слева \u2B05 и:\n",
            "     * Сохраняйте файлы \U0001F4BE!\n",
            "     * Делитесь кодом \U0001F4E4!\n",
            "     * Открывайте проекты \U0001F4C2!\n", NULL}, "4"},
        {"\U0001F6E0","Используйте дополнительные возможности", (char*[]){
            "   - Меняйте язык программирования через строку поиска \U0001F50D!\n",
            "   - Нажмите Ctrl+Enter для быстрого запуска кода!\n", NULL}, "2"}
    };

    int choice;
    do {
        printDelay("\nВыберите действие:\n", 0);
        for(int i=0; i<9; i++) printDelay(menu[i], 0);
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if(choice >=2 && choice <=5) {
            int idx = choice-2;
            showSection(sectionParams[idx][0], sectionParams[idx][1], 
                      sectionParams[idx][2], atoi(sectionParams[idx][3]));
        }
        else if(choice && choice<8) functions[choice]();
        else if(choice == 8) showHeader();
        else if(choice) printf("Некорректный ввод!\n");
    } while(choice != 0);
}

int main() {
    srand(time(NULL));
    getUserName();
    showHeader();
    showMenu();
    
    printf("Завершаем работу...\n");
    usleep(3000000);
    showHeader();
    return 0;
}
