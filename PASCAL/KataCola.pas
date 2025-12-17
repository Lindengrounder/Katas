program DrinkIngredientsInfo;

uses
  SysUtils;

type
  TComponent = record
    Name: string;
    Description: string;
  end;

const
  Components: array[1..8] of TComponent = (
    (Name: 'Вода'; Description: 'основной компонент напитка. В умеренных количествах безопасна для потребления.'),
    (Name: 'Сахар'; Description: 'естественный подсластитель. Избыточное потребление может привести к ожирению и диабету.'),
    (Name: 'Краситель e150d'; Description: 'придает цвет напиткам. В малых количествах безопасен, но возможны аллергические реакции.'),
    (Name: 'Регулятор кислотности e338'; Description: 'регулирует уровень pH. В больших количествах может вызвать раздражение желудка.'),
    (Name: 'Ароматизаторы'; Description: 'придают напитку вкус и аромат. Могут вызывать аллергические реакции у чувствительных лиц.'),
    (Name: 'Кофеин (не более 150 мг/л)'; Description: 'стимулирует центральную нервную систему. В умеренных количествах безопасен, но избыток может вызвать бессонницу и нервозность.'),
    (Name: 'Подсластители (E950, E951, E952, E954)'; Description: 'используются для придания сладости без добавления сахара. Безопасны в рекомендованных дозах, но возможны побочные эффекты.'),
    (Name: 'Стабилизатор e414'; Description: 'сохраняет консистенцию напитка. В малых количествах безопасен, но возможны расстройства ЖКТ при больших дозах.')
  );

procedure PrintComponentInfo(index: Integer);
begin
  Writeln;
  Writeln(Components[index].Name, ':');
  Writeln('Описание и влияние на организм: ', Components[index].Description);
end;

procedure PrintDrinkIngredientsInfo;
var
  i, choice: Integer;
begin
  Writeln('Состав напитка:');
  Writeln('Выберите компонент для получения информации (1-8):');

  // Выводим меню
  for i := 1 to 8 do
  begin
    Writeln(i, ') ', Components[i].Name);
  end;

  // Получаем выбор пользователя
  Write('Ваш выбор: ');
  Readln(choice);

  // Проверяем корректность ввода
  if (choice < 1) or (choice > 8) then
  begin
    Writeln('Неверный выбор. Пожалуйста, выберите номер из меню.');
    Exit;
  end;

  // Выводим информацию о выбранном компоненте
  PrintComponentInfo(choice);
end;

begin
  PrintDrinkIngredientsInfo;
end.
