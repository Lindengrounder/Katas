program financial_tracker
    implicit none
    
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

    print *, "Simple Financial Tracker"
    print *, "------------------------"
    
    do
        print '(/, "Current balance: ", F0.2)', balance
        print *, "1. Add Income"
        print *, "2. Add Expense"
        print *, "3. Show History"
        print *, "4. Exit"
        print *, "Enter choice: "
        
        ! Read input with error handling
        read(*,'(A)') input
        read(input, *, iostat=io) choice
        
        if (io /= 0) then
            print *, "Invalid input. Please enter 1-4"
            cycle
        end if

        select case (choice)
        case (1) ! Add Income
            print *, "Enter description: "
            read(*,'(A)') desc
            print *, "Enter amount: "
            read(*, *, iostat=io) amt
            if (io /= 0 .or. amt <= 0) then
                print *, "Invalid amount!"
                cycle
            end if
            
            if (transaction_count < max_trans) then
                transaction_count = transaction_count + 1
                transactions(transaction_count) = transaction(desc, amt, "Income")
                balance = balance + amt
            else
                print *, "Transaction limit reached!"
            end if

        case (2) ! Add Expense
            print *, "Enter description: "
            read(*,'(A)') desc
            print *, "Enter amount: "
            read(*, *, iostat=io) amt
            if (io /= 0 .or. amt <= 0) then
                print *, "Invalid amount!"
                cycle
            end if
            
            if (transaction_count < max_trans) then
                transaction_count = transaction_count + 1
                transactions(transaction_count) = transaction(desc, amt, "Expense")
                balance = balance - amt
            else
                print *, "Transaction limit reached!"
            end if

        case (3) ! Show History
            print '(/, "Transaction History:")'
            print *, "----------------------------------------------------"
            do i = 1, transaction_count
                print '(A10, ": ", A50, " - ", F0.2)', &
                    trim(transactions(i)%type), &
                    trim(transactions(i)%description), &
                    transactions(i)%amount
            end do
            print *, "----------------------------------------------------"

        case (4) ! Exit
            exit

        case default
            print *, "Invalid choice!"
        end select
    end do

    print *, "Goodbye!"
end program financial_tracker
