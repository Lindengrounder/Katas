# KataPassGen14.py
# 11/01/2025 - протестирована на онлайн компиляторе JDoodle.com
# 11/05/2025 - улучшенная версия

import random
from random import choice
from string import ascii_uppercase, ascii_lowercase, digits

# Константы для символов
SYMBOLS_L = ascii_uppercase
SYMBOLS_S = ascii_lowercase
SYMBOLS_N = digits
SYMBOLS_SPECIAL = '-+=*?!%@_'

def generate_random_string(symbols, length):
    """Генерирует случайную строку заданной длины из предоставленных символов."""
    return ''.join(choice(symbols) for _ in range(length))

def generate_password(length):
    """Генерирует пароль, состоящий из разных типов символов."""
    rand1 = generate_random_string(SYMBOLS_SPECIAL, length)
    rand2 = generate_random_string(SYMBOLS_L, length)
    rand3 = generate_random_string(SYMBOLS_S, length)
    rand4 = generate_random_string(SYMBOLS_N, length)
    
    # Объединяем все части в один пароль
    password = rand1 + rand2 + rand3 + rand4
    # Перемешиваем символы для большей случайности
    password = ''.join(random.sample(password, len(password)))
    
    return password

def main():
    cs = random.randint(2, 9)
    password = generate_password(cs)
    print("Generated Password:", password)

if __name__ == "__main__":
    main()
