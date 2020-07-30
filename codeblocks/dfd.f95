function circle(r)
    implicit none

    real:: circle

    real :: r
    real :: pi

    pi = 4*atan(1.0)

    circle = pi * r**2
end function

program calling_func

    real :: a
    a = circle(2.0)

    print*, "The area of a circle with radius 2.0 is"
    print*, a
end program
