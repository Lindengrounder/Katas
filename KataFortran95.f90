program modern_financial_tracker
    implicit none
    
    ! Тип данных для транзакции (фиксированные длины строк)
    type transaction
        character(len=50) :: description
        real :: amount
        character(len=10) :: type
    end type transaction

    integer, parameter :: max_trans = 100
    type(transaction) :: transactions(max_trans)
    integer :: transaction_count = 0
    real :: balance = 0.0
    integer :: choice, i, io
    character(len=50) :: desc
    real :: amt
    character(len=10) :: input

    print *, "Modern Financial Tracker (Fortran 95)"
    print *, "-------------------------------------"
    
    do
        ! Главное меню
        print '(/, "Current balance: ", F0.2)', balance
        print *, "1. Add Income"
        print *, "2. Add Expense"
        print *, "3. Show History"
        print *, "4. Exit"
        print *, "Enter choice: "
        
        read(*, '(A)') input
        read(input, *, iostat=io) choice
        
        if (io /= 0 .or. choice < 1 .or. choice > 4) then
            print *, "Invalid input. Please enter 1-4"
            cycle
        end if

        select case (choice)
        case (1)
            call add_transaction("Income    ")
        case (2)
            call add_transaction("Expense   ")
        case (3)
            call show_history()
        case (4)
            exit
        end select
    end do
    
    print *, "Goodbye!"
    
contains
    ! Вспомогательные процедуры
    subroutine add_transaction(t_type)
        character(len=10), intent(in) :: t_type
        logical :: valid
        
        if (transaction_count >= max_trans) then
            print *, "Transaction limit reached!"
            return
        end if
        
        print *, "Enter description: "
        read(*, '(A)') desc
        
        call read_amount(amt, valid)
        if (.not. valid) return
        
        transaction_count = transaction_count + 1
        transactions(transaction_count) = transaction( &
            trim(desc), &
            amt, &
            t_type &
        )
        
        if (t_type == "Income    ") then
            balance = balance + amt
        else
            balance = balance - amt
        end if
    end subroutine add_transaction

    subroutine show_history()
        print *, ""
        print *, "Transaction History:"
        print *, "----------------------------------------------------"
        do i = 1, transaction_count
            print '(A10, ": ", A50, " - ", F0.2)', &
                transactions(i)%type, &
                transactions(i)%description, &
                transactions(i)%amount
        end do
        print *, "----------------------------------------------------"
    end subroutine show_history

    subroutine read_amount(amount, valid)
        real, intent(out) :: amount
        logical, intent(out) :: valid
        character(len=20) :: input
        integer :: io
        
        valid = .false.
        
        do
            print *, "Enter amount: "
            read(*, '(A)') input
            read(input, *, iostat=io) amount
            
            if (io == 0 .and. amount > 0) then
                valid = .true.
                exit
            else
                print *, "Invalid amount! Try again."
            end if
        end do
    end subroutine read_amount
end program modern_financial_tracker
