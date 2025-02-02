module financial_types
    use, intrinsic :: iso_fortran_env, only: input_unit, output_unit
    implicit none
    private

    type, public :: Transaction
        character(len=:), allocatable :: description
        real :: amount
        character(len=:), allocatable :: type
    contains
        procedure :: format => transaction_format
    end type Transaction

    type, public :: FinancialTracker
        private
        type(Transaction), allocatable :: transactions(:)
        real :: balance = 0.0
        integer :: transaction_count = 0
    contains
        procedure :: add_income => add_income
        procedure :: add_expense => add_expense
        procedure :: show_history => show_history
        procedure :: get_balance
    end type FinancialTracker

    interface FinancialTracker
        module procedure tracker_init
    end interface

contains
    function tracker_init(max_trans) result(tracker)
        integer, intent(in) :: max_trans
        type(FinancialTracker) :: tracker
        allocate(tracker%transactions(max_trans))
    end function

    function transaction_format(this) result(str)
        class(Transaction), intent(in) :: this
        character(len=:), allocatable :: str
        character(len=20) :: amount_str
        
        write(amount_str, '(F0.2)') this%amount
        str = this%type // ': ' // this%description // ' - ' // trim(amount_str)
    end function

    subroutine add_income(this)
        class(FinancialTracker), intent(inout) :: this
        type(Transaction) :: t
        character(len=:), allocatable :: desc
        real :: amt

        print '(A)', "Enter description: "
        desc = read_string()
        
        amt = read_positive_number("Enter amount: ")
        
        if (this%transaction_count < size(this%transactions)) then
            this%transaction_count = this%transaction_count + 1
            this%transactions(this%transaction_count) = &
                Transaction(desc, amt, "Income")
            this%balance = this%balance + amt
        else
            print '(A)', "Transaction limit reached!"
        end if
    end subroutine

    subroutine add_expense(this)
        class(FinancialTracker), intent(inout) :: this
        type(Transaction) :: t
        character(len=:), allocatable :: desc
        real :: amt

        print '(A)', "Enter description: "
        desc = read_string()
        
        amt = read_positive_number("Enter amount: ")
        
        if (this%transaction_count < size(this%transactions)) then
            this%transaction_count = this%transaction_count + 1
            this%transactions(this%transaction_count) = &
                Transaction(desc, amt, "Expense")
            this%balance = this%balance - amt
        else
            print '(A)', "Transaction limit reached!"
        end if
    end subroutine

    subroutine show_history(this)
        class(FinancialTracker), intent(in) :: this
        integer :: i
        character(len=:), allocatable :: line
        
        print '(/, A)', "Transaction History:"
        line = repeat('-', 60)
        print '(A)', line
        
        do i = 1, this%transaction_count
            print '(A)', this%transactions(i)%format()
        end do
        
        print '(A)', line
    end subroutine

    real function get_balance(this)
        class(FinancialTracker), intent(in) :: this
        get_balance = this%balance
    end function

    function read_string() result(str)
        character(len=:), allocatable :: str
        character(len=256) :: buffer
        integer :: length
        
        read(input_unit, '(A)') buffer
        length = len_trim(buffer)
        str = buffer(1:length)
    end function

    function read_positive_number(prompt) result(num)
        character(len=*), intent(in) :: prompt
        real :: num
        integer :: ierr
        
        do
            write(output_unit, '(A)', advance='no') prompt
            read(input_unit, *, iostat=ierr) num
            
            if (ierr == 0 .and. num > 0) exit
            print '(A)', "Invalid input. Please enter a positive number."
        end do
    end function
end module financial_types

program modern_financial_tracker
    use financial_types
    implicit none
    type(FinancialTracker) :: tracker
    integer :: choice, max_trans = 100
    character(len=:), allocatable :: input_str
    
    tracker = FinancialTracker(max_trans)
    
    print '(A)', "Modern Financial Tracker"
    print '(A)', "------------------------"
    
    do
        print '(/, A, F0.2)', "Current balance: ", tracker%get_balance()
        print '(A)', "1. Add Income"
        print '(A)', "2. Add Expense"
        print '(A)', "3. Show History"
        print '(A)', "4. Exit"
        write(output_unit, '(A)', advance='no') "Enter choice: "
        
        input_str = read_string()
        read(input_str, *, iostat=choice) choice
        
        select case (choice)
        case (1)
            call tracker%add_income()
        case (2)
            call tracker%add_expense()
        case (3)
            call tracker%show_history()
        case (4)
            exit
        case default
            print '(A)', "Invalid choice!"
        end select
    end do
    
    print '(A)', "Goodbye!"
end program modern_financial_tracker
