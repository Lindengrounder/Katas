<?php
class Transaction {
    public $description;
    public $amount;
    public $type;

    public function __construct($description, $amount, $type) {
        $this->description = $description;
        $this->amount = $amount;
        $this->type = $type;
    }
}

class FinancialTracker {
    const MAX_TRANS = 100;
    private $transactions = [];
    private $balance = 0.0;

    public function run() {
        echo "Simple Financial Tracker\n";
        echo "------------------------\n";

        while (true) {
            echo "\nCurrent balance: " . number_format($this->balance, 2) . "\n";
            echo "1. Add Income\n";
            echo "2. Add Expense\n";
            echo "3. Show History\n";
            echo "4. Exit\n";
            
            $choice = $this->readInput("Enter choice: ");
            
            switch ($choice) {
                case 1:
                    $this->addTransaction("Income");
                    break;
                case 2:
                    $this->addTransaction("Expense");
                    break;
                case 3:
                    $this->showHistory();
                    break;
                case 4:
                    echo "Goodbye!\n";
                    exit;
                default:
                    echo "Invalid choice!\n";
            }
        }
    }

    private function addTransaction($type) {
        if (count($this->transactions) >= self::MAX_TRANS) {
            echo "Transaction limit reached!\n";
            return;
        }

        $desc = $this->readInput("Enter description: ");
        $amt = $this->readNumericInput("Enter amount: ");

        if ($amt <= 0) {
            echo "Invalid amount!\n";
            return;
        }

        $this->transactions[] = new Transaction($desc, $amt, $type);
        $this->balance += ($type === "Income") ? $amt : -$amt;
    }

    private function showHistory() {
        echo "\nTransaction History:\n";
        echo str_repeat("-", 50) . "\n";
        
        foreach ($this->transactions as $transaction) {
            printf("%-10s: %-50s - %s\n",
                $transaction->type,
                $transaction->description,
                number_format($transaction->amount, 2)
            );
        }
        
        echo str_repeat("-", 50) . "\n";
    }

    private function readInput($prompt) {
        echo $prompt;
        return trim(fgets(STDIN));
    }

    private function readNumericInput($prompt) {
        while (true) {
            $input = $this->readInput($prompt);
            if (is_numeric($input)) {
                return (float)$input;
            }
            echo "Invalid input. Please enter a number.\n";
        }
    }
}

// Запуск приложения
$tracker = new FinancialTracker();
$tracker->run();
?>
