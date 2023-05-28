import numpy as np
import matplotlib.pyplot as plt
import math 
import cmath

s1 = 0
s2 = 0
a = []
b = []
r = 11
T = 40
N = 10
def E(n, m):
    return (2*math.pi*(n-m))/(math.log(N))

def x(n, m):
    a = (1/1-(2j*math.pi*(n-m)/math.log(N)))/(math.sqrt(math.log(N)))
    b = (N**(1-(2j*math.pi*(n-m)/math.log(N)))-1)
    return a*b

for t in np.arange(0,1,0.001):
    C=0
    Z=0
    for n in range(0,r):
        s2=0    
        for m in range(0,r):
            s1=0
            for k in range(0,r):
                s1 += (1/2.0)*x(n,k)*x(k,m)*(E(k,m)*cmath.exp(1j*E(n,k)*t) - E(n,k)*cmath.exp(1j*E(k,m)*t))
            s2 += s1*np.conjugate(s1)
        Z += cmath.exp(-E(n,0)/T)
        C += (cmath.exp(-E(n,0)/T)*s2)
    a.append(t)
    b.append(C/Z)
data = np.column_stack((a, b))
np.savetxt('test.dat', data , delimiter='  ')


plt.plot(a,b)
plt.show()