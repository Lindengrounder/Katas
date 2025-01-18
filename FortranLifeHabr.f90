program life
! чисто последовательный вариант программы
! https://habr.com/ru/articles/726654/

implicit none

! здесь мы задаём количество байтов
! для каждой ячейки - вдруг операции над
! целыми словами окажутся эффективными? (нет)
integer, parameter :: matrix_kind = 1

integer, parameter :: generations = 2 ! автомат рассматривает 2 поколения
integer, parameter :: rows = 1000, cols = 1000 ! размеры поля
integer, parameter :: steps = 10000 ! количество шагов

! описываем игровое поле. значения элементов могут быть целыми 0 или 1
integer (kind=matrix_kind) :: field (0:rows+1, 0:cols+1, generations)

integer :: thisstep = 1, nextstep =2 ! индексы массива для шагов
! при желании это можно легко обобщить на автомат с памятью больше 1 шага

integer :: i ! счётчик шагов
integer :: clock_cnt1, clock_cnt2, clock_rate ! для работы с таймером

! инициализируем поле на шаге thisstep начальной конфигурацией
call init_matrix (field (:, :, thisstep))

! засечём время
call system_clock (count=clock_cnt1)

! вызовем процедуру выполнения шага в цикле для заданного числа шагов
do i = 1, steps
  ! тут мы берём сечение массива по thisstep и преобразовываем в nextstep
  call process_step (field (:, :, thisstep), field (:, :, nextstep))
  ! следующий шаг становится текущим
  thisstep = nextstep
  ! а для следующего шага снова возвращаемся к другому сечению
  nextstep = 3 - thisstep
end do

! узнаем новое значение таймера и его частоту
call system_clock (count=clock_cnt2, count_rate=clock_rate)

! напечатаем затраченное время и оценку производительности
print *, (clock_cnt2-clock_cnt1)/clock_rate, 'сек, ', & 
  int(rows*cols,8)*steps/(clock_cnt2-clock_cnt1)*clock_rate, 'ячеек/с'

! выведем результирующую конфигурацию в файл для контроля
call output_matrix (field (:, :, thisstep))

! разместим подпрограммы тут же, чтобы оптимизатору было проще
contains

! проинициализируем, просто воткнув одну "мигалку" в чистое поле
pure subroutine init_matrix (m)
  integer (kind=matrix_kind), intent (out) :: m (0:,0:)
  m = 0
  m (50, 50) = 1
  m (50, 51) = 1
  m (50, 52) = 1
end subroutine init_matrix

! выведем матрицу в файл при помощи пробелов, звёздочек и грязного хака
subroutine output_matrix (m)
  integer (kind=matrix_kind), intent (in) :: m (0:,0:)
  integer :: rows, cols
  integer :: i, j
  integer :: outfile
  rows = size (m, dim=1) - 2
  cols = size (m, dim=2) - 2
  open (file = 'life.txt', newunit=outfile) ! вылетает в компиляторе jdoodle.com
  do i = 1, rows
    ! выводим в каждой позиции строки символ, код которого является
    ! суммой кода пробела и значения ячейки (0 или 1), умноженного
    ! на разность между звёздочкой и пробелом
    write (outfile, '(*(A1))') (char (ichar (' ') + &
      m(i, j)*(ichar ('*') - ichar (' '))), j=1, cols)
  end do
  close (outfile)
end subroutine output_matrix

! здесь самое интересное – обработка шага
! для начала простой последовательный алгоритм

pure subroutine process_step (m1, m2)

  integer (kind=matrix_kind), intent (in) :: m1 (0:,0:)
  integer (kind=matrix_kind), intent (out) :: m2 (0:,0:)
  integer :: rows, cols
  integer :: i, j, s

  ! восстанавливаем значения rows и cols
  ! конечно, мы могли бы из просто передать в параметрах, но так культурнее
  rows = size (m1, dim=1) - 2
  cols = size (m1, dim=2) - 2

  ! обычные последовательные вложенные циклы
  ! поскольку в Фортране массивы хранятся по столбцам, то j раньше i
  do j = 1, cols
    do i = 1, rows

      ! считаем количество живых соседей
      s = m1 (i-1, j) + m1 (i+1, j) + m1 (i-1, j-1) + m1 (i+1, j-1) + &
          m1 (i, j-1) + m1 (i-1, j+1) + m1 (i, j+1) + m1 (i+1, j+1)

      ! присваиваем значение выходной клетке 
      select case (s)
        case (3)
          m2 (i, j) = 1
        case (2)
          m2 (i, j) = m1 (i, j)
        case default
          m2 (i, j) = 0
      end select

    end do
  end do

  ! закольцуем игровое поле, используя гало в массиве, 
  ! дублирующее крайние элементы с другой стороны массива
  m2 (0,:) = m2 (rows, :)
  m2 (rows+1, :) = m2 (1, :)
  m2 (:, 0) = m2 (:, cols)
  m2 (:, cols+1) = m2 (:, 1)

end subroutine process_step

end program life
