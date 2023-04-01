program diffusion
  implicit none
  integer, parameter :: dp = selected_real_kind(15, 300)
  real(dp) :: kb, T, M, n, zeta, D, DH
  real :: pi = 3.14159265358979323846
  kb = 1.38e-23_dp
  T = 298.0_dp
  M = 1.1525801e-23_dp
  n = 6.023e23_dp
  zeta = 0.46_dp
  D = 0.0206_dp * (pi * kb * T / M) ** 0.5 * (6.0_dp / (pi * n * zeta ** 2)) ** (1.0_dp / 3.0_dp) * &
      (1.0_dp - zeta) ** 3 / (zeta * (1.0_dp - zeta / 2.0_dp))
  DH = 0.0625_dp * (pi * kb * T / M) ** 0.5 * (6.0_dp / (pi * n * zeta ** 2)) ** (1.0_dp / 3.0_dp) * &
       (1.0_dp - zeta) ** 3 / (zeta * (1.0_dp - zeta / 2.0_dp))
  print *, D
  print *, DH
end program diffusion
