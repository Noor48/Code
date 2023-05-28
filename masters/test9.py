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
    for n in range(0, r):
        c = 0
        for m in range(0, r):
            b = 0
            for k in range(0, r):
                b += (1/2.0) * x(n, k) * x(k, m) * (E(k, m) * cmath.exp(1j * E(n, k) * t) - E(n, k) * cmath.exp(1j * E(k, m) * t))
            c += b * np.conjugate(b)

        Z += cmath.exp(-E(n,0)/T)
        C += (cmath.exp(-E(n,0)/T)*c)
    if n==5:
        x.append(C/Z)
    return C/Z
    


# Parallel execution using joblib
results = Parallel(n_jobs=-1)(delayed(compute_s2)(t) for t in np.arange(0, 1, 0.001))

a = np.arange(0, 1, 0.001)
b = results
#x = np.array([res[0] for res in results])
#p1 = np.array([res[0] for res in results])
#q = np.array([res[1] for res in results])
#s = np.array([res[2] for res in results])
#data = np.column_stack((a,p,q,s))
#np.savetxt('test.dat', data, delimiter='  ')

plt.plot(a,b,label='n=10')
plt.plot(a,x,label='n=2')
#plt.plot(a,s,label='n=5')
#plt.plot(a,p1,label='n=1')
plt.legend()
plt.show()