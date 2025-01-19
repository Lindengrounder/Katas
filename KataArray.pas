//Программа для поиска наибольшего элемента
//протестирована на JDoofle.com 19/01/2025
program  n_4;
  var i, imax: integer; 
      a: array[1..30] of integer;
begin 
  randomize;

  for i:=1 to 30 do a[i]:=random(100);
  for i:=1 to 30 do write(a[i],' ');

  imax:=1;

  for i:=2 to 30 do
    if a[i]>a[imax] then
       imax:=i;

  write('Наибольший элемент   a[', imax, ']=', a[imax])

end.
