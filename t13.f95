program simplified_diffusion_coefficient
  implicit none

  real(kind=8) :: kb, T, zetaH, zetaS, zetaSH, D

  ! Boltzmann constant in CGS units
  kb = 1.38d-16

  ! Temperature in Kelvin
  T = 373

  ! Zeta values from table
  zetaH = 2.29
  zetaS = 15.8
  zetaSH = 6.21

  ! Compute diffusion coefficient in cm^2/s
  D = (kb*T)/(zetaH + zetaS + zetaSH) * 1d15

  ! Output result
  write(*,*) "Diffusion coefficient (cm^2/s) = ", D

end program simplified_diffusion_coefficient
