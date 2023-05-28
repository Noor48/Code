import numpy as np
import matplotlib.pyplot as plt
import math
from joblib import Parallel, delayed
import cmath

s1 = 0
s2 = 0
a = []
b = []
r = 10
T = 40
N = 10
def E(n, m):
    return (2*math.pi)

def x(n, m):
    return (1/1-np.imag(E(n,m)))(N**(1-np.imag((0,E(n,m))))-1)/(math.sqrt(math.log(N)))

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
    return C/Z
    


# Parallel execution using joblib
results = Parallel(n_jobs=-1)(delayed(compute_s2)(t) for t in np.arange(0, 1, 0.001))

a = np.arange(0, 1, 0.001)
b = results

data = np.column_stack((a, b))
np.savetxt('test.dat', data, delimiter='  ')

plt.plot(a, b)
plt.show()
