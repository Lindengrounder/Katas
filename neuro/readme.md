Запускаем терминал Powershell от имени администратора
ставим chocolately (если не стоит)
 choco upgrade chocolatey  (чтобы обновить его если стоял уже)
ставим g++ есл ине стоит: choco install mingw -y
в папке с кодом запускаем компилятор: g++ -std=c++11 -o perceptron perceptron.cpp
после запускаем exe: ./perceptron
Резултатат примерно: Epoch 0, Error: 1
Epoch 100, Error: 0
Epoch 200, Error: 0
Epoch 300, Error: 0
Epoch 400, Error: 0
Epoch 500, Error: 0
Epoch 600, Error: 0
Epoch 700, Error: 0
Epoch 800, Error: 0
Epoch 900, Error: 0
Testing:
Input: (0, 0) => Output: 0
Input: (0, 1) => Output: 0
Input: (1, 0) => Output: 0
Input: (1, 1) => Output: 1
