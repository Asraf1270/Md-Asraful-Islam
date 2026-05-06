PROGRAM character_format
    IMPLICIT NONE
    CHARACTER(LEN=10) :: name = "Alice"
    CHARACTER(LEN=5) :: city = "NYC"
    
    WRITE(*, '(A)') "String output:"
    WRITE(*, '(A10)') name     ! 10 spaces: "     Alice"
    WRITE(*, '(A3)') city      ! 3 spaces: "NYC" (truncated if needed)
    WRITE(*, '(A)') name       ! Auto-adjusts to string length: "Alice"
    
    ! Mixing types
    WRITE(*, '(A, I3, A, F6.2)') "Age: ", 25, " Height: ", 5.75
END PROGRAM character_format