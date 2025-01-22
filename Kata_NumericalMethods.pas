// Привет! Можешь написать красивый приветственный код на паскаль, реализующий числовые методы с пояснениями и комментариями. 
// Было бы здорово если бы этот код показывал преимущества императивной парадигмы программирования, 
// при этом был бы не очень объемным и реализовывался в консоли. Если будет меню - это будет преимуществом

// Пояснения:

//    Инициализация: Программа начинается с очистки экрана и инициализации пунктов меню, которые содержат названия операций и соответствующие методы.
//    Меню: Пользователь выбирает операцию из предложенного меню. Это демонстрирует императивный подход, где программа явно указывает порядок выполнения действий.
//    Ввод данных: После выбора операции пользователь вводит два числа, которые будут использоваться в операции.
//    Выполнение операции: В зависимости от выбранной операции (сложение, вычитание, умножение или деление), программа выполняет соответствующую операцию и выводит результат.
//    Обработка ошибок: Программа проверяет на деление на ноль и сообщает об ошибке, если это происходит.
// Этот код демонстрирует простоту и мощь императивного программирования, где каждый шаг явно указывается и контролируется программой.


program NumericalMethods;

{ Программа для демонстрации числовых методов с использованием императивной парадигмы программирования }

uses
  crt; { Для использования функций модуля CRT }

const
  MAX_MENU_ITEMS = 4; { Максимальное количество пунктов меню }

type
  { Определение типа данных для операций }
  Operation = (Addition, Subtraction, Multiplication, Division);
  
  { Определение типа данных для чисел }
  Number = record
    value: real;
  end;
  
  { Определение типа данных для методов }
  Method = record
    name: string;
    operation: Operation;
  end;
  
  { Определение типа данных для меню }
  MenuItem = record
    label: string;
    method: Method;
  end;
  
var
  menuItems: array[1..MAX_MENU_ITEMS] of MenuItem;
  currentMethod: Method;
  num1, num2: Number;
  result: real;
  choice: integer;
  
{ Инициализация пунктов меню }
procedure InitializeMenu;
var
  i: integer;
begin
  menuItems[1].label := 'Сложение';
  menuItems[1].method.name := 'Addition';
  menuItems[1].method.operation := Addition;
  
  menuItems[2].label := 'Вычитание';
  menuItems[2].method.name := 'Subtraction';
  menuItems[2].method.operation := Subtraction;
  
  menuItems[3].label := 'Умножение';
  menuItems[3].method.name := 'Multiplication';
  menuItems[3].method.operation := Multiplication;
  
  menuItems[4].label := 'Деление';
  menuItems[4].method.name := 'Division';
  menuItems[4].method.operation := Division;
end;
  
{ Основная программа }
begin
  ClrScr; { Очистка экрана }
  
  InitializeMenu; { Инициализация пунктов меню }
  
  WriteLn('Добро пожаловать в программу числовых методов!');
  WriteLn('Выберите операцию:');
  
  { Отображение меню }
  for i := 1 to MAX_MENU_ITEMS do
    WriteLn(i:2, '. ', menuItems[i].label);
  
  Write('Ваш выбор: ');
  ReadLn(choice);
  
  { Выполнение выбранной операции }
  currentMethod := menuItems[choice].method;
  WriteLn('Введите первое число:');
  ReadLn(num1.value);
  WriteLn('Введите второе число:');
  ReadLn(num2.value);
  
  case currentMethod.operation of
    Addition: result := num1.value + num2.value;
    Subtraction: result := num1.value - num2.value;
    Multiplication: result := num1.value * num2.value;
    Division: if num2.value = 0 then
              WriteLn('Ошибка: деление на ноль')
            else
              result := num1.value / num2.value;
  end;
  
  WriteLn('Результат: ', result:0:2);
  ReadLn; { Пауза для просмотра результата }
end.
