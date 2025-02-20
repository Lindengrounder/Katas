// Инициализация игры
const gameBoard = document.getElementById('game-board');
const statusBody = document.getElementById('status-body');
const turnCounter = document.getElementById('turn-counter');
const nextTurnButton = document.getElementById('next-turn');
const saveCodeInput = document.getElementById('save-code');
const saveGameButton = document.getElementById('save-game');
const loadGameButton = document.getElementById('load-game');

let gameState = {
    countries: [
        { name: 'Оранжевая', color: 'orange', gold: 100, economy: 0, soldiers: 0 },
        { name: 'Синяя', color: 'blue', gold: 100, economy: 0, soldiers: 0 },
        { name: 'Красная', color: 'red', gold: 100, economy: 0, soldiers: 0 },
        { name: 'Зеленая', color: 'green', gold: 100, economy: 0, soldiers: 0 }
    ],
    board: Array(16).fill(null),
    turn: 0
};

// Инициализация игрового поля
function initializeGame() {
    gameState.board.fill('orange', 0, 4); // Оранжевая страна
    gameState.board.fill('blue', 4, 8);  // Синяя страна
    gameState.board.fill('red', 8, 12);  // Красная страна
    gameState.board.fill('green', 12, 16); // Зеленая страна

    renderBoard();
    renderStatus();
}

// Рендеринг игрового поля
function renderBoard() {
    gameBoard.innerHTML = '';
    gameState.board.forEach((cell, index) => {
        const cellDiv = document.createElement('div');
        cellDiv.className = cell || '';
        cellDiv.textContent = `Солдат: ${getSoldiersInCell(index)}`;
        gameBoard.appendChild(cellDiv);
    });
}

// Рендеринг статуса стран
function renderStatus() {
    statusBody.innerHTML = '';
    gameState.countries.forEach(country => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${country.name}</td>
            <td>${country.gold}</td>
            <td>${country.economy}</td>
            <td>${country.soldiers}</td>
        `;
        statusBody.appendChild(row);
    });
    turnCounter.textContent = gameState.turn;
}

// Получение количества солдат в клетке
function getSoldiersInCell(index) {
    return Math.floor(gameState.countries.find(c => c.color === gameState.board[index])?.soldiers / 4 || 0);
}

// Ход игрока
document.getElementById('end-turn').addEventListener('click', () => {
    const goldForSoldiers = parseInt(document.getElementById('gold-for-soldiers').value) || 0;
    const goldForEconomy = parseInt(document.getElementById('gold-for-economy').value) || 0;

    const player = gameState.countries[0];
    if (goldForSoldiers + goldForEconomy > player.gold) {
        alert('Недостаточно золота!');
        return;
    }

    player.gold -= goldForSoldiers + goldForEconomy;
    player.soldiers += goldForSoldiers;
    player.economy += goldForEconomy;

    renderStatus();
});

// Следующий ход
nextTurnButton.addEventListener('click', () => {
    gameState.turn++;
    updateIncome();
    renderStatus();
});

// Обновление дохода
function updateIncome() {
    gameState.countries.forEach(country => {
        const income = 10 + country.economy * 5 + countControlledCells(country.color) * 5;
        country.gold += income;
    });
}

// Подсчет контролируемых клеток
function countControlledCells(color) {
    return gameState.board.filter(cell => cell === color).length;
}

// Сохранение игры
saveGameButton.addEventListener('click', () => {
    saveCodeInput.value = JSON.stringify(gameState);
});

// Загрузка игры
loadGameButton.addEventListener('click', () => {
    try {
        gameState = JSON.parse(saveCodeInput.value);
        renderBoard();
        renderStatus();
    } catch (e) {
        alert('Ошибка загрузки保存状态!');
    }
});

// Инициализация игры
initializeGame();
