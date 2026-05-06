program concat_char
CHARACTER(len=10) :: a, b, c

a = 'Apple Computer'
b = 'Murrays Mathematical Biology'
c(1:4) = a(1:4)
c(5:8) = b(3:6)
c(8:10) = b(8:10)

print *, a, " ", b, " ", c
end program