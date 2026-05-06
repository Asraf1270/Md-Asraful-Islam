PROGRAM real_format
    IMPLICIT NONE
    REAL :: x = 123.456, y = 0.005, z = 123456.789
    
    WRITE(*, '(A)') "Fixed-point format (F):"
    WRITE(*, '(F10.3)') x    ! 10 spaces, 3 decimals: "   123.456"
    WRITE(*, '(F8.2)') y     ! 8 spaces, 2 decimals: "    0.01" (rounded!)
    WRITE(*, '(F12.4)') z    ! 12 spaces, 4 decimals: "123456.7890"
    
    WRITE(*, '(A)') "Scientific notation (E):"
    WRITE(*, '(E12.4)') x    ! " 0.1235E+03"
    WRITE(*, '(E10.2)') y    ! "0.50E-02"
    WRITE(*, '(E15.6)') z    ! " 1.234568E+05"
    
    ! Comparing F and E for same number
    WRITE(*, '(A, F10.4, A, E12.4)') "F format:", 0.000123, "  E format:", 0.000123
END PROGRAM real_format