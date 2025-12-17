// прога на паскале - не знаю нафиг я решил его вспомнить
// jdoodle.com выполнил один раз - но очень тормозно. А потом вообще завис
// видимо день был не очень и мне хотелось каких-то извращений - поэтому паскаль
// 04.01.2025
program Factorization;

uses
  crt;

var
  number, i: integer;

begin
  ClrScr;
  Write('Enter an integer number: ');
  ReadLn(number);
  i := 2;
  while i <= number do
  begin
    if number mod i = 0 then
    begin
      Write(i);
      number := number div i;
      if number > 1 then
        Write('*');
    end
    else
      i := i + 1;
  end;
  WriteLn;
  WriteLn('max = ', i);
  ReadLn;
end.
