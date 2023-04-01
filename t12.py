import math
#double kb, T, M, n, zeta
#Boltzman constant
kb = 1.38 * pow(10, -23)
#temperature
T = 298
#Mass of particle
M = 1.1525801*pow(10,-23)
#
n = 6.023*pow(10,23)
#Zeta value
zeta = 0.46

A = pow((math.pi*kb*T)/M, (1/2))
B = pow(6/(math.pi*n*pow(zeta,2)), (1/3))
C = pow(1-zeta , 3)/(zeta * (1 - 0.5*zeta))

D = 0.0206*A*B*C

DH = A*B*C/16

print(D)
print(DH)