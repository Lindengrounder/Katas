# 04.02.2025 протестировано на JDoodle
#
# Консольный вариант игры "жизнь" для онлайн компилятора jdoodle, поле 11х11

import copy
import time

# Размер поля
SIZE = 11

# Инициализация поля
def initialize_board():
    return [[0 for _ in range(SIZE)] for _ in range(SIZE)]

# Вывод поля в консоль
def print_board(board):
    for row in board:
        print(' '.join(['#' if cell else '.' for cell in row]))
    print()

# Получение количества живых соседей
def count_neighbors(board, x, y):
    count = 0
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i == 0 and j == 0:
                continue
            nx, ny = x + i, y + j
            if 0 <= nx < SIZE and 0 <= ny < SIZE:
                count += board[nx][ny]
    return count

# Обновление состояния поля
def update_board(board):
    new_board = copy.deepcopy(board)
    for x in range(SIZE):
        for y in range(SIZE):
            neighbors = count_neighbors(board, x, y)
            if board[x][y]:
                if neighbors < 2 or neighbors > 3:
                    new_board[x][y] = 0
            else:
                if neighbors == 3:
                    new_board[x][y] = 1
    return new_board

# Пример начальной конфигурации (глайдер)
def set_glider(board):
    board[1][2] = 1
    board[2][3] = 1
    board[3][1] = 1
    board[3][2] = 1
    board[3][3] = 1

# Основной цикл игры
def main():
    board = initialize_board()
    set_glider(board)
    
    while True:
        print_board(board)
        board = update_board(board)
        time.sleep(1)

if __name__ == "__main__":
    main()
