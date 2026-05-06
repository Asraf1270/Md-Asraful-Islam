PROGRAM positional_editing
    IMPLICIT NONE
    
    ! X = horizontal spacing
    WRITE(*, '(A, 5X, A)') "Name", "Score"  ! 5 spaces between
    
    ! T = tab to column
    WRITE(*, '(T5, A, T20, A)') "Column5", "Column20"
    
    ! TR = tab right (forward)
    WRITE(*, '(A, TR10, A)') "Start", "After10spaces"
    
    ! TL = tab left (backward)
    WRITE(*, '(A, TL5, A)') "Overwrite", "Back5"
    
    ! Creating a table
    WRITE(*, '(/"Employee Data:")')
    WRITE(*, '(T5, A, T20, A, T35, A)') "Name", "Department", "Salary"
    WRITE(*, '(T5, A, T20, A, T35, F8.2)') "John", "Engineering", 55000.00
    WRITE(*, '(T5, A, T20, A, T35, F8.2)') "Sarah", "Marketing", 48000.00
END PROGRAM positional_editing