/* протестировал 26.12.2025 на https://www.codechef.com/ide - ведет себя скверно, не получается вводить данные корректно*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
        for (const auto& transaction : transactions) {
            std::cout << std::setw(12) << transaction.date << std::setw(20) << transaction.description 
                      << std::setw(12) << std::fixed << std::setprecision(2) << transaction.amount << std::endl;
        }
    }
};

int main() {
    FamilyBudget budget;
    int choice;
    std::string date, description;
    double amount;

    do {
        std::cout << "\n1. Добавить доход\n2. Добавить расход\n3. Показать баланс\n4. Показать все транзакции\n0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите дату (ДД.ММ.ГГГГ): ";
                std::cin >> date;
                std::cout << "Введите описание: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Введите сумму дохода: ";
                std::cin >> amount;
                budget.addIncome(date, description, amount);
                break;
            case 2:
                std::cout << "Введите дату (ДД.ММ.ГГГГ): ";
                std::cin >> date;
                std::cout << "Введите описание: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Введите сумму расхода: ";
                std::cin >> amount;
                budget.addExpense(date, description, amount);
                break;
            case 3:
                budget.printBalance();
                break;
            case 4:
                budget.printTransactions();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
