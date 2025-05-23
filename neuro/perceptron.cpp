#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Функция активации (ступенчатая функция)
int step_function(double x) {
    return (x >= 0) ? 1 : 0;
}

// Класс перцептрона
class Perceptron {
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;

public:
    Perceptron(size_t input_size, double lr = 0.1) : learning_rate(lr) {
        // Инициализация случайных весов и смещения
        std::srand(std::time(nullptr));
        for (size_t i = 0; i < input_size; ++i) {
            weights.push_back(static_cast<double>(std::rand()) / RAND_MAX * 2 - 1);
        }
        bias = static_cast<double>(std::rand()) / RAND_MAX * 2 - 1;
    }

    // Метод для предсказания
    int predict(const std::vector<double>& inputs) {
        double sum = bias;
        for (size_t i = 0; i < inputs.size(); ++i) {
            sum += inputs[i] * weights[i];
        }
        return step_function(sum);
    }

    // Метод для обучения
    void train(const std::vector<std::vector<double>>& X, const std::vector<int>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (size_t i = 0; i < X.size(); ++i) {
                int prediction = predict(X[i]);
                int error = y[i] - prediction;
                for (size_t j = 0; j < weights.size(); ++j) {
                    weights[j] += learning_rate * error * X[i][j];
                }
                bias += learning_rate * error;
            }
            // Выводим ошибку каждые 100 эпох
            if (epoch % 100 == 0) {
                int total_error = 0;
                for (size_t i = 0; i < X.size(); ++i) {
                    total_error += std::abs(y[i] - predict(X[i]));
                }
                std::cout << "Epoch " << epoch << ", Error: " << total_error << std::endl;
            }
        }
    }
};

int main() {
    // Простой пример обучения перцептрона на задаче AND
    std::vector<std::vector<double>> X = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    std::vector<int> y = {0, 0, 0, 1};

    Perceptron perceptron(2, 0.1);
    perceptron.train(X, y, 1000);

    // Тестирование
    std::cout << "Testing:" << std::endl;
    for (const auto& input : X) {
        std::cout << "Input: (" << input[0] << ", " << input[1] << ") => Output: " << perceptron.predict(input) << std::endl;
    }

    return 0;
}