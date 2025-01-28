<?php
// Хранение данных в JSON файле
$file = 'posts.json';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $title = $_POST['title'] ?? '';
    $content = $_POST['content'] ?? '';
    if ($title && $content) {
        $posts = json_decode(file_get_contents($file), true) ?: [];
        $posts[] = ['id' => uniqid(), 'title' => $title, 'content' => $content];
        file_put_contents($file, json_encode($posts));
    }
}

$posts = json_decode(file_get_contents($file), true) ?: [];
$postId = $_GET['id'] ?? '';
$post = null;
if ($postId) {
    foreach ($posts as $p) {
        if ($p['id'] === $postId) {
            $post = $p;
            break;
        }
    }
}
?>
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <title>Мини-блог</title>
</head>
<body>
    <?php if ($post): ?>
        <h1><?= htmlspecialchars($post['title']) ?></h1>
        <p><?= nl2br(htmlspecialchars($post['content'])) ?></p>
        <a href="/">Назад</a>
    <?php else: ?>
        <h1>Мой блог</h1>
        <form method="post">
            <input type="text" name="title" placeholder="Заголовок" required><br>
            <textarea name="content" placeholder="Текст" required></textarea><br>
            <button type="submit">Опубликовать</button>
        </form>
        <h2>Записи:</h2>
        <?php foreach ($posts as $p): ?>
            <div>
                <h3><a href="?id=<?= $p['id'] ?>"><?= htmlspecialchars($p['title']) ?></a></h3>
            </div>
        <?php endforeach; ?>
    <?php endif; ?>
</body>
</html>
