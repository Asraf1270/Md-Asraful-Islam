PROGRAM named_format
    IMPLICIT NONE
    REAL :: score1 = 85.5, score2 = 92.75, score3 = 78.25
    
    ! Define a named format
    100 FORMAT("Student ", I1, " score: ", F6.2, "/100")
    200 FORMAT(/"===== FINAL REPORT =====")
    300 FORMAT(A10, F8.2, I5)
    
    WRITE(*, 200)  ! Use format 200
    WRITE(*, 100) 1, score1
    WRITE(*, 100) 2, score2
    WRITE(*, 100) 3, score3
    
    ! Table format
    WRITE(*, '(/A)') "Grade Table:"
    WRITE(*, 300) "John", 85.5, 92
    WRITE(*, 300) "Alice", 92.75, 88
    WRITE(*, 300) "Bob", 78.25, 95
END PROGRAM named_format