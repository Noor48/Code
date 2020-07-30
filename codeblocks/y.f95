program sum_series
    implicit none

    real :: x, x2, x3, x4, x6, x8, x10, sum
    print*, "Type of value of x"
    read*, x

    x2 = x*x
    x4 = x2*x2/24
    x6 = x4*x2/30
    x8 = x6*x2/56
    x10 = x8*x2/90

    sum = 1.0 - .5*x2 + x4 - x6 + x8 - x10
    print*, "Value of x = ", x, "Sum = ", sum

end program
