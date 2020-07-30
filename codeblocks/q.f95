program dynamic_array
    implicit none

    integer, dimension (:,:), allocatable :: a
    integer :: dim1, dim2
    integer :: i, j
    print*, "Give dimensions dim1, and dim2:"
    read*, dim1, dim2

    allocate (a(dim1, dim2))
    do i = 1, dim1
        do j = 1, dim2
            a(i, j) = i*j
            print*, "a(", i, ",", j, ")=", a(i, j)
        end do
    end do

    deallocate (a)
end program dynamic_array
