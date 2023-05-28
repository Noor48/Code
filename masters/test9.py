import numpy as np
import matplotlib.pyplot as plt
import math
from joblib import Parallel, delayed
import cmath


a = []
b = []
r = 11
T = 40
N = 10
x = []
d = []
e = []
def E(n, m):
    return (2*math.pi*(n-m))/(math.log(N))

def x(n, m):
    a = (1/1-(2j*math.pi*(n-m)/math.log(N)))/(math.sqrt(math.log(N)))
    b = (N**(1-(2j*math.pi*(n-m)/math.log(N)))-1)
    return a*b

def compute_s2(t):
    C = 0
    Z = 0
    b1 = np.array([])
    c1 = np.array([])
    d = np.array([])
    e = np.array([])
    for n in range(0, r):
        c = 0
        for m in range(0, r):
            b = 0
            for k in range(0, r):
                b += (1/2.0) * x(n, k) * x(k, m) * (E(k, m) * cmath.exp(1j * E(n, k) * t) - E(n, k) * cmath.exp(1j * E(k, m) * t))
            c += b * np.conjugate(b)

        Z += cmath.exp(-E(n,0)/T)
        C += (cmath.exp(-E(n,0)/T)*c)

        if n == 1:
            c1 = np.append(c1, C/Z)

        if n == 2:
            d = np.append(d, C/Z)

        if n == 5:
            e = np.append(e, C/Z)
    return C/Z,c,d,e
    


# Parallel execution using joblib
results = Parallel(n_jobs=-1)(delayed(compute_s2)(t) for t in np.arange(0, 1, 0.001))

a = np.arange(0, 1, 0.001)
#b1 = np.array([res[0] for res in results])
c1 = np.array([res[0] for res in results])
d = np.array([res[1] for res in results])
e = np.array([res[2] for res in results])
#data = np.column_stack((a,p,q,s))
#np.savetxt('test.dat', data, delimiter='  ')

#plt.plot(a,b,label='n=10')
plt.plot(a,c1,label='n=1')
plt.plot(a,d,label='n=2')
plt.plot(a,e,label='n=5')
plt.legend()
plt.show()