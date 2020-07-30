program formattedio
    implicit none

    real :: pi = 3.1415927
    real :: x, y, z
    print*, "(a, i3.3)", "Result = ",1
    print*, "(f6.3)", pi
    print*, "(e16.4)", pi/100

    x = 10.3324
    y = 00.23234
    z = 32.0934
    print*, "(3(f6.3))", x, y, z

end program
