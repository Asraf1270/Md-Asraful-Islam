PROGRAM simple_format
    IMPLICIT NONE
    INTEGER :: a = 123, b = 45, c = 6789
    
    ! I = Integer format, 4 = width of 4 characters
    ! 1x for 1 space
    WRITE(*, '(I4, I4,1x, I4)') a, b, c
END PROGRAM simple_format