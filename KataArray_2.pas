//Программа для сортировки массива
//протестирована на JDoofle.com 19/01/2025
program sort;

var   n, i, j, x, imax: integer;
      a: array [1..10] of integer;

begin
  //write("введите массив из 10 чисел", ' '):
  for i:=1 to 10 do read (a[i]);
  for i:=1 to 10 do write (a[i], ' ');

  for i:=1 to 9 do
  begin
    imax:=i;
    for j:=i+1 to 10 do
      if a[j]>a[imax] then
        imax:=j;

    x:=a[i];
    a[i]:=a[imax];
    a[imax]:=x
  end;

  for i:=1 to 10 do
    write(a[i], ' ')
end.
