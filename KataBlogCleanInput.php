<?php
// Временное хранилище в оперативной памяти
$posts = [];

// Функция для очистки строки от символов Backspace
function cleanInput($input) {
    // Удаляем символы Backspace и всё, что было "удалено" с их помощью
    while (strpos($input, "\x08") !== false) {
        $input = preg_replace('/[^\x08]\x08/', '', $input);
    }
    return $input;
}

// Основной цикл программы
while (true) {
    echo "1. Добавить запись\n";
    echo "2. Показать все записи\n";
    echo "3. Выйти\n";
    echo "Выберите действие: ";
    $choice = trim(fgets(STDIN));

    if ($choice == '1') {
        // Добавление записи
        echo "Введите заголовок: ";
        $title = cleanInput(trim(fgets(STDIN)));
        echo "Введите текст: ";
        $content = cleanInput(trim(fgets(STDIN)));

        $posts[] = ['id' => uniqid(), 'title' => $title, 'content' => $content];
        echo "Запись добавлена!\n\n";
    } elseif ($choice == '2') {
        // Показать все записи
        if (empty($posts)) {
            echo "Записей нет.\n\n";
        } else {
            foreach ($posts as $post) {
                echo "ID: " . $post['id'] . "\n";
                echo "Заголовок: " . $post['title'] . "\n";
                echo "Текст: " . $post['content'] . "\n";
                echo "----------------------------\n";
            }
        }
    } elseif ($choice == '3') {
        // Выход
        echo "Выход из программы.\n";
        break;
    } else {
        echo "Неверный выбор. Попробуйте снова.\n\n";
    }
}
