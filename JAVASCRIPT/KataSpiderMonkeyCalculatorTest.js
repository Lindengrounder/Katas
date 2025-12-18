//Двта теста 13.01.2025 - нифига не запустилось

function calculator() {
    const readline = require('readline-sync');

    console.log("Простейший калькулятор");
    const num1 = parseFloat(readline.question("Введите первое число: "));
    const operator = readline.question("Введите оператор (+, -, *, /): ");
    const num2 = parseFloat(readline.question("Введите второе число: "));

    let result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 !== 0) {
                result = num1 / num2;
            } else {
                console.log("Ошибка: деление на ноль");
                return;
            }
            break;
        default:
            console.log("Ошибка: неверный оператор");
            return;
    }

    console.log(`Результат: ${result}`);
}

calculator();

/*
function add(a, b) {
    return a + b;
}


function subtract(a, b) {
    return a - b;
}


function multiply(a, b) {
    return a * b;
}


function divide(a, b) {
    return a / b;
}

function prompt ()
{}
function calculator() 
{
    //var prompt = 0;
    var operator = prompt("(+, -, *, /):");
    var a = prompt(":");
    var b = prompt(":");

    switch (operator) {
        case "+" :
            console.log(add(a, b));
            break;
        case "-" :
            console.log(subtract(a, b));
            break;
        case "*" :
            console.log(multiply(a, b));
            break;
        case "/" :
            console.log(divide(a, b));
            break;
        default:
            console.log(".");
    }
}

calculator();*/
