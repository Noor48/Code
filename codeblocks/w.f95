program calling_func
    implicit none
    real :: x, y, z, disc
    x = 1.0
    y = 5.0
    z = 2.0

    call intent_example(x, y, z, disc)

    print*, "This value of the discrimination is"
    print*, disc

end program

subroutine intent_example(a, b, c, d)
    implicit none

    real, intent(in) :: a
    real, intent(in) :: b
    real, intent(in) :: c
    real, intent(out) :: d

    d = b*b - 4.0*a*c

end subroutine
