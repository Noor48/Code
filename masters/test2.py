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

def x(n, m):
    if n == m:
        return 1/2
    else:
        return ((1 - pow(-1, n + m)) / (pow(math.pi, 2))) * ((1 / pow(n + m, 2)) - (1 / pow(n - m, 2)))

def E(n, m):
    return pow(math.pi, 2) * (pow(n, 2) - pow(m, 2))

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
