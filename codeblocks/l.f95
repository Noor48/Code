program test_ptr
    implicit none

    real, pointer :: p1, p2
    real, target :: t1 = 10, t2 = -17
    p1 => t1
    p2 => p1
    write(*,*) "p1, p2, t1, t2 = ", p1, p2 ,t1, t2
    p1 => t2
    write(*,*) "p1, p2, t1, t2 = ", p1, p2 ,t1, t2

end program
