<?php
// Предположим, что у нас есть API шлюза MVB, доступное через HTTP-запросы

$apiUrl = "http://mvb-gateway/api/read"; // URL API для чтения данных с MVB
$apiKey = "your_api_key_here"; // Ключ API для авторизации

// Параметры запроса (например, адрес устройства на шине MVB)
$params = [
    'device_id' => 123, // ID устройства на шине MVB
    'register' => 0x10, // Регистр, который нужно прочитать
];

// Добавляем API-ключ в параметры
$params['api_key'] = $apiKey;

// Формируем URL с параметрами
$requestUrl = $apiUrl . '?' . http_build_query($params);

// Выполняем HTTP-запрос
$response = file_get_contents($requestUrl);

// Проверяем ответ
if ($response === FALSE) {
    die("Ошибка при выполнении запроса к API MVB.");
}

// Декодируем JSON-ответ (предполагаем, что API возвращает JSON)
$data = json_decode($response, true);

if (json_last_error() === JSON_ERROR_NONE && isset($data['value'])) {
    echo "Значение регистра: " . $data['value'];
} else {
    echo "Ошибка при обработке ответа от API MVB.";
}
?>
