class Transaction:
    def __init__(self, description, amount, t_type):
        self.description = description
        self.amount = amount
        self.t_type = t_type

class FinancialTracker:
    def __init__(self):
        self.transactions = []
        self.balance = 0.0

    def add_transaction(self, t_type):
        if len(self.transactions) >= 100:
            print("Transaction limit reached!")
            return
        
        desc = input("Enter description: ")
        amt = self.read_amount()
        if amt is None:
            return
        
        self.transactions.append(Transaction(desc, amt, t_type))
        self.balance += amt if t_type == "Income" else -amt

    def show_history(self):
        print("\nTransaction History:")
        print("-" * 60)
        for t in self.transactions:
            print(f"{t.t_type:10}: {t.description:50} - {t.amount:.2f}")
        print("-" * 60)

    def read_amount(self):
        while True:
            try:
                amt = float(input("Enter amount: "))
                if amt > 0:
                    return amt
                else:
                    print("Invalid amount! Try again.")
            except ValueError:
                print("Invalid input! Enter a valid number.")

    def run(self):
        print("Modern Financial Tracker (Python)")
        print("-" * 40)
        
        while True:
            print(f"\nCurrent balance: {self.balance:.2f}")
            print("1. Add Income")
            print("2. Add Expense")
            print("3. Show History")
            print("4. Exit")
            choice = input("Enter choice: ")
            
            if choice == '1':
                self.add_transaction("Income")
            elif choice == '2':
                self.add_transaction("Expense")
            elif choice == '3':
                self.show_history()
            elif choice == '4':
                print("Goodbye!")
                break
            else:
                print("Invalid input. Please enter 1-4.")

if __name__ == "__main__":
    tracker = FinancialTracker()
    tracker.run()
