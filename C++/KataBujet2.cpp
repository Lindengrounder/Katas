#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

struct Transaction {
    std::string date;
    std::string description;
    double amount;
};

class FamilyBudget {
private:
    std::vector<Transaction> transactions;
    double balance;

public:
    FamilyBudget() : balance(0.0) {}

    void addIncome(const std::string& date, const std::string& description, double amount) {
        transactions.push_back({date, description, amount});
        balance += amount;
    }

    void addExpense(const std::string& date, const std::string& description, double amount) {
        transactions.push_back({date, description, -amount});
        balance -= amount;
    }

    void printBalance() const {
        std::cout << "Текущий баланс: " << std::fixed << std::setprecision(2) << balance << " руб." << std::endl;
    }

    void printTransactions() const {
        std::cout << "Список транзакций:" << std::endl;
        std::cout << std::setw(12) << "Дата" << std::setw(20) << "Описание" << std::setw(12) << "Сумма" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        for (const auto& t : transactions) {
            std::cout << std::setw(12) << t.date << std::setw(20) << t.description 
                      << std::setw(12) << std::fixed << std::setprecision(2) << t.amount << std::endl;
        }
    }
};

int main() {
    FamilyBudget budget;
    int choice = -1;
    std::string date, description;
    double amount = 0;

    while (true) {
        std::cout << "\n1. Добавить доход\n2. Добавить расход\n3. Показать баланс\n4. Показать транзакции\n0. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::cout << "Введите дату: ";
            std::getline(std::cin, date);
            std::cout << "Введите описание: ";
            std::getline(std::cin, description);
            std::cout << "Введите сумму дохода: ";
            std::cin >> amount;
            budget.addIncome(date, description, amount);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (choice == 2) {
            std::cout << "Введите дату: ";
            std::getline(std::cin, date);
            std::cout << "Введите описание: ";
            std::getline(std::cin, description);
            std::cout << "Введите сумму расхода: ";
            std::cin >> amount;
            budget.addExpense(date, description, amount);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } else if (choice == 3) {
            budget.printBalance();

        } else if (choice == 4) {
            budget.printTransactions();

        } else if (choice == 0) {
            std::cout << "Выход..." << std::endl;
            break;
        } else {
            std::cout << "Неверный выбор!\n";
        }
    }

    return 0;
}