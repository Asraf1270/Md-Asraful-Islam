PROGRAM report_card
    IMPLICIT NONE
    CHARACTER(LEN=20) :: name = "John Smith"
    INTEGER :: roll = 101
    REAL :: marks(5) = (/85.5, 92.0, 78.5, 88.0, 91.5/)
    REAL :: total, percentage
    CHARACTER(LEN=2) :: grade
    INTEGER :: i
    
    ! Calculate
    total = SUM(marks)
    percentage = total / 5.0
    
    ! Determine grade
    IF (percentage >= 90.0) THEN
        grade = "A+"
    ELSE IF (percentage >= 80.0) THEN
        grade = "A"
    ELSE IF (percentage >= 70.0) THEN
        grade = "B"
    ELSE IF (percentage >= 60.0) THEN
        grade = "C"
    ELSE
        grade = "F"
    END IF
    
    ! Output with formatting
    WRITE(*, '(//T20, A)') "REPORT CARD"
    WRITE(*, '(T15, 30("-"))')
    WRITE(*, '(/T5, A, T30, A)') "Name:", name
    WRITE(*, '(T5, A, T30, I3)') "Roll No:", roll
    WRITE(*, '(T5, A, T30, F5.2, A)') "Percentage:", percentage, "%"
    WRITE(*, '(T5, A, T30, A)') "Grade:", grade
    
    WRITE(*, '(/T5, A)') "Subject-wise Marks:"
    WRITE(*, '(T10, A, T25, A)') "Subject", "Marks"
    WRITE(*, '(T10, 20("-"), T25, 5("-"))')
    
    DO i = 1, 5
        WRITE(*, '(T10, A, I1, T25, F6.2, "/100")') "Subject ", i, marks(i)
    END DO
    
    WRITE(*, '(T10, 20("-"), T25, 5("-"))')
    WRITE(*, '(T10, A, T25, F6.2)') "TOTAL", total
END PROGRAM report_card