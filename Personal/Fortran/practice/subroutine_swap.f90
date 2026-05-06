PROGRAM subroutine_swap
    IMPLICIT NONE
    INTEGER :: a = 10, b = 20
    
    PRINT *, "Before subroutine call:"
    PRINT *, "a =", a, "b =", b
    
    CALL swap_values(a, b)
    
    PRINT *, "After subroutine call:"
    PRINT *, "a =", a, "b =", b
    
END PROGRAM subroutine_swap

! Subroutine definition
SUBROUTINE swap_values(x, y)
    IMPLICIT NONE
    INTEGER, INTENT(INOUT) :: x, y
    INTEGER :: temp
    
    temp = x
    x = y
    y = temp
    
END SUBROUTINE swap_values