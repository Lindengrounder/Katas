import serial

# Настройка UART (пример для подключения к MVB через COM-порт)
mvb_uart = serial.Serial(
    port='/dev/ttyUSB0',  # Порт UART
    baudrate=9600,        # Скорость передачи
    parity=serial.PARITY_EVEN,  # Четность
    stopbits=serial.STOPBITS_ONE,  # Стоп-биты
    bytesize=serial.EIGHTBITS  # Размер байта
)

# Чтение данных с шины MVB
def read_mvb_data():
    if mvb_uart.in_waiting > 0:
        data = mvb_uart.read(mvb_uart.in_waiting)
        print("Received data:", data)
    else:
        print("No data available.")

# Запись данных на шину MVB
def write_mvb_data(data):
    mvb_uart.write(data)
    print("Data sent:", data)

# Пример использования
write_mvb_data(b'\x01\x02\x03')  # Отправка данных
read_mvb_data()  # Чтение данных
