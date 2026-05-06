PROGRAM literal_text
    IMPLICIT NONE
    REAL :: temp = 23.5
    INTEGER :: humidity = 65
    
    WRITE(*, '("Temperature: ", F5.1, "°C")') temp
    WRITE(*, '("Humidity: ", I3, "%")') humidity
    
    ! Multiple lines
    WRITE(*, '(A, /, A)') "First line", "Second line"  ! / = newline
    
    ! Tab character
    WRITE(*, '(A, T20, A)') "Name", "Score"  ! T20 = tab to column 20
    WRITE(*, '(A, T20, I3)') "John", 85
    WRITE(*, '(A, T20, I3)') "Sarah", 92
END PROGRAM literal_text