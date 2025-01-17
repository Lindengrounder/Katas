# Welcome to JDoodle!
#
# You can execute code here in 88 languages. Right now you’re in the Python3 IDE.
#
#  1. Click the orange Execute button ️▶ to execute the sample code below and see how it works.
#  2. Want help writing or debugging code? Type a query into JDroid on the right hand side ---------------->
#  3. Try the menu buttons on the left. Save your file, share code with friends and open saved projects.
#
# Want to change languages? Try the search bar up the top.

# Проверка вывода консоли
def print_message():
    print("Привет!")  # Пример сообщения

# Вызов функции
print_message()

# Проверка, было ли сообщение выведено
output = "Привет!"  # Задаем ожидаемый вывод

if output in str(print_message()):
    print("Вывод консоли правильный")
else:
    print("Ошибка в выводе консоли")
