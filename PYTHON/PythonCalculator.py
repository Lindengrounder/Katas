
# Функция для сложения двух чисел
def add(x, y):
    return x + y

# Функция для вычитания двух чисел
def subtract(x, y):
    return x - y

# Функция для умножения двух чисел
def multiply(x, y):
    return x * y

# Функция для деления двух чисел
def divide(x, y):
    if y != 0:
        return x / y
    else:
        return "Ошибка! Деление на ноль."

# Основная программа калькулятора
def calculator():
    operation = input("Введите операцию (+, -, *, /): ")
    num1 = float(input("Введите первое число: "))
    num2 = float(input("Введите второе число: "))

    if operation == "+":
        print(f"Результат: {add(num1, num2)}")
    elif operation == "-":
        print(f"Результат: {subtract(num1, num2)}")
    elif operation == "*":
        print(f"Результат: {multiply(num1, num2)}")
    elif operation == "/":
        print(f"Результат: {divide(num1, num2)}")
    else:
        print("Неизвестная операция!")

# Запуск калькулятора
calculator()
