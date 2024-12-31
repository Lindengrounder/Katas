#код на python (протестирован на JDoodle.com)
#
#Нахождение всех простых чисел до заданного лимита
#
#дата теста: 31.12.2024
#

# Функция для проверки, является ли число простым
def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

# Ввод лимита от пользователя
limit = int(input("Enter the limit number: "))

# Вывод всех простых чисел до заданного лимита
for num in range(2, limit + 1):
    if is_prime(num):
        print(num)
