class Transaction {
    constructor(description, amount, type) {
        this.description = description;
        this.amount = amount;
        this.type = type;
    }
}

class FinancialTracker {
    constructor(maxTrans) {
        this.maxTrans = maxTrans;
        this.transactions = [];
        this.balance = 0.0;
    }

    run() {
        console.log("Modern Financial Tracker (JavaScript)");
        console.log("-------------------------------------");

        const readline = require('readline').createInterface({
            input: process.stdin,
            output: process.stdout
        });

        const menu = () => {
            console.log(`\nCurrent balance: ${this.balance.toFixed(2)}`);
            console.log("1. Add Income");
            console.log("2. Add Expense");
            console.log("3. Show History");
            console.log("4. Exit");

            readline.question("Enter choice: ", (choice) => {
                switch (choice) {
                    case '1':
                        this.addTransaction("Income", readline, menu);
                        break;
                    case '2':
                        this.addTransaction("Expense", readline, menu);
                        break;
                    case '3':
                        this.showHistory();
                        menu();
                        break;
                    case '4':
                        console.log("Goodbye!");
                        readline.close();
                        break;
                    default:
                        console.log("Invalid choice!");
                        menu();
                }
            });
        };

        menu();
    }

    addTransaction(type, readline, callback) {
        if (this.transactions.length >= this.maxTrans) {
            console.log("Transaction limit reached!");
            callback();
            return;
        }

        readline.question("Enter description: ", (desc) => {
            this.readAmount(readline, (amount) => {
                this.transactions.push(new Transaction(desc, amount, type));
                this.balance += (type === "Income") ? amount : -amount;
                callback();
            });
        });
    }

    showHistory() {
        console.log("\nTransaction History:");
        console.log("-".repeat(60));
        this.transactions.forEach((t) => {
            console.log(`${t.type.padEnd(10)}: ${t.description.padEnd(50)} - ${t.amount.toFixed(2)}`);
        });
        console.log("-".repeat(60));
    }

    readAmount(readline, callback) {
        const askAmount = () => {
            readline.question("Enter amount: ", (input) => {
                const amount = parseFloat(input);
                if (isNaN(amount) || amount <= 0) {
                    console.log("Invalid amount! Try again.");
                    askAmount();
                } else {
                    callback(amount);
                }
            });
        };
        askAmount();
    }
}

// Запуск программы
const tracker = new FinancialTracker(100);
tracker.run();
