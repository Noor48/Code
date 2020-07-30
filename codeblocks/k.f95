program f
    implicit none

    type:: atom
        character(len=2) :: label
        real :: x, y, z
    end type atom

    type(atom) :: carbon1
    carbon1%label = "C"
    carbon1%x = 0.000
    carbon1%y = 1.3567
    carbon1%z = 2.5000

    print*, carbon1
end program
