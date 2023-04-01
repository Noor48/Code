import math
#Boltzamna constant
kb = 1.38 * pow(10,-16)
#Given Temperature
T = 373
#Zeta values from table
zetaH = 2.29
zetaS = 15.8
zetaSH = 6.21

D = (kb*T)/(zetaH + zetaS +zetaSH) * pow(10,15)

print(D)