import numpy as np
import matplotlib.pyplot as plt
import math 
import qutip as Q
import cmath

s1 = 0
s2 = 0
a = []
b = []
def x(n,m):
    if n==m:
        return 1/2
    
    else:
        return ((1-pow(-1,n+m))/(pow(math.pi,2)))*((1/pow(n+m,2))-(1/pow(n-m,2)))

def E(n,m):
    return pow(math.pi,2)*(pow(n,2)-pow(m,2))

for t in np.arange(0,1,0.001):
    for n in range(0,100,1):
        s1=0
        for m in range(0,100,1):
            s2=0
            for k in range(0,100,1):
                s1 += (1/2.0)*x(n,k)*x(k,m)*(E(k,m)*cmath.exp(1j*E(n,k)*t) - E(n,k)*cmath.exp(1j*E(k,m)*t))
            s2 += s1*np.conjugate(s1)
    a.append(t)
    b.append(s2)
data = np.column_stack((a, b))
np.savetxt('test.dat', data , delimiter='  ')


plt.plot(a,b)
plt.show()