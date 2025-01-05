! Код на Fortran (протестирован на JDoodle.com)
!
! Нахождение всех простых множителей числа
!
! Дата теста 05:01:2025

program Factorization

    implicit none
    integer :: number, i

    write(*,*) 'Enter an integer number: '
    read(*,*) number
    i = 2
    do while (i <= number)
        if (mod(number, i) == 0) then
            write(*,*) i
            number = number / i
            if (number > 1) write(*,*) '*'
        else
            i = i + 1
        end if
    end do
    write(*,*)
    write(*,*) 'max = ', i

end program Factorization
