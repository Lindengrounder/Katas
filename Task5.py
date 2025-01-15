# Определение функции поиска самого длинного общего префикса
def longest_common_prefix(words):
    if not words:
        return ""

    # Находим минимальную длину слова в массиве
    min_len = min(len(word) for word in words)
    prefix = ""

    # Перебираем символы по индексу
    for i in range(min_len):
        char = words[0][i]
        # Проверяем, совпадает ли символ в данной позиции у всех слов
        if all(word[i] == char for word in words):
            prefix += char  # Добавляем символ к общему префиксу
        else:
            break  # Выходим из цикла, если символы не совпадают

    return prefix

# Пример использования
words = ["робот", "ров", "ролка", "ролики"]
result = longest_common_prefix(words)
print(result)