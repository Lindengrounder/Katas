<?php
// Исходный массив
$array = [5, 2, 8, 1, 3, 11, 4, -1, 0, 1, 0.25];

// Вывод исходного массива
echo "Исходный массив: " . implode(", ", $array) . PHP_EOL;

// Сортировка массива
sort($array);

// Вывод отсортированного массива
echo "Отсортированный массив: " . implode(", ", $array) . PHP_EOL;
?>
