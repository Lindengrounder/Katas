<?php
class DatabaseHandler {
    private $connection;
    private $is_test_mode;
    private $simulatedData = [];

    public function __construct($host, $user, $pass, $db, $test_mode = false) {
        $this->is_test_mode = $test_mode;
        
        if (!$this->is_test_mode) {
            // Реальное подключение к БД
            $this->connection = new mysqli($host, $user, $pass, $db);
            if ($this->connection->connect_error) {
                die("Connection failed: " . $this->connection->connect_error);
            }
        } else {
            // Симуляционные данные для тестов
            $this->simulatedData['users'] = [
                ['id' => 1, 'name' => 'Test User 1', 'email' => 'test1@example.com'],
                ['id' => 2, 'name' => 'Test User 2', 'email' => 'test2@example.com']
            ];
        }
    }

    public function query($sql) {
        if ($this->is_test_mode) {
            // Симуляция запросов
            if (stripos($sql, 'SELECT') !== false) {
                return true; // Имитация успешного запроса
            }
            if (stripos($sql, 'INSERT') !== false) {
                // Имитация добавления данных
                preg_match('/VALUES\s*\(([^)]+)\)/i', $sql, $matches);
                if ($matches) {
                    $values = array_map('trim', explode(',', $matches[1]));
                    $newUser = [
                        'id' => count($this->simulatedData['users']) + 1,
                        'name' => trim($values[0], "'"),
                        'email' => trim($values[1], "'")
                    ];
                    $this->simulatedData['users'][] = $newUser;
                }
                return true;
            }
            return true;
        } else {
            // Реальное выполнение запроса
            return $this->connection->query($sql);
        }
    }

    public function fetch($result) {
        if ($this->is_test_mode) {
            // Возвращаем симуляционные данные
            return $this->simulatedData['users'];
        } else {
            // Реальное получение данных
            $rows = [];
            while ($row = $result->fetch_assoc()) {
                $rows[] = $row;
            }
            return $rows;
        }
    }

    public function close() {
        if (!$this->is_test_mode) {
            $this->connection->close();
        }
    }
}

// Определяем режим работы через GET-параметр
$test_mode = isset($_GET['test']) && $_GET['test'] == 1;

// Создаем экземпляр обработчика БД
$db = new DatabaseHandler('localhost', 'root', 'password', 'my_db', $test_mode);

// Пример выполнения запросов
$db->query("INSERT INTO users (name, email) VALUES ('New User', 'new@example.com')");
$result = $db->query("SELECT * FROM users");
$users = $db->fetch($result);

// Вывод результатов
echo "<pre>";
echo "Database Results:\n";
foreach ($users as $user) {
    echo "ID: {$user['id']}, Name: {$user['name']}, Email: {$user['email']}\n";
}

$db->close();
?>
