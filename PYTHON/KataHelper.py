import webbrowser

choice = input("Выберите программу (1:ImgBurn, 2:WinCDEmu, 3:CDBurnerXP): ")

if choice == "1":
    print("Инструкция для ImgBurn:\n1. Установите ImgBurn (пропускайте рекламу)")
    webbrowser.open("https://www.imgburn.com")
    print("2. Запустите: Create image file from disc\n3. Укажите DVD-привод и путь сохранения\n4. Нажмите Read")
elif choice == "2":
    print("Инструкция для WinCDEmu:\n1. Установите WinCDEmu")
    webbrowser.open("https://wincdemu.sysprogs.org")
    print("2. ПКМ на DVD-диске в проводнике → Create ISO image\n3. Укажите путь и сохраните")
elif choice == "3":
    print("Инструкция для CDBurnerXP:\n1. Установите CDBurnerXP")
    webbrowser.open("https://cdburnerxp.se")
    print("2. Запустите: Copy disc → Image file\n3. Нажмите Copy disc")
else:
    print("Ошибка выбора")

print("\nПримечания:\n- Проверьте отсутствие защиты на DVD\n- Убедитесь в исправности привода")
