# Welcome 
#
# You can execute code here 
n = int(input("Введите число: "))
факториал = 1
if n == 0:
    факториал = 1
else:
    for i in range(1, n + 1):
        факториал = факториал * i
print("Факториал числа", n, "равен", факториал)
