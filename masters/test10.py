import numpy as np
import matplotlib.pyplot as plt
import math 
import cmath

s1 = 0
s2 = 0
a = []
b = []
c=[]
d=[]
e=[]
r = 11
T = 40
N = 10
def E(n, m):
    return (2*math.pi*(n-m))/(math.log(N))

def x(n, m):
    a = (1/1-(2j*math.pi*(n-m)/math.log(N)))/(math.sqrt(math.log(N)))
    b = (N**(1-(2j*math.pi*(n-m)/math.log(N)))-1)
    return a*b

n_values = [2, 5, 10, 20]

# Initialize the arrays for each n value
arrays = {n: [] for n in n_values}

# Existing code
r = 20  # Assuming r is defined somewhere
T = 40.0  # Assuming T is defined somewhere

for t in np.arange(0, 1, 0.001):
    Z = 0
    C = 0
    s3 = 0
    
    for n in range(0, r):
        s2 = 0
        
        for m in range(0, r):
            s1 = 0
            
            for k in range(0, r):
                s1 += (1 / 2.0) * x(n, k) * x(k, m) * (E(k, m) * cmath.exp(1j * E(n, k) * t) - E(n, k) * cmath.exp(1j * E(k, m) * t))
            
            s2 += s1 * np.conjugate(s1)
        
        Z += cmath.exp(-E(n, 0) / T)
        C += cmath.exp(-E(n, 0) / T) * s2
        
        s3 = C / Z
        
        # Check if the current n is in the list of desired values
        if n in n_values:
            arrays[n].append(s3)
    
    # Check if all desired n values have been collected
    if all(len(arr) > 0 for arr in arrays.values()):
        break
    
    a.append(t)

# Save the arrays to separate files
#for n, arr in arrays.items():
#    filename = f'test_n{n}.dat'
#    np.savetxt(filename, np.column_stack((np.arange(0, len(arr) * 0.001, 0.001), arr)), delimiter='  ')

plt.plot(a,arrays[2],label="2")
plt.plot(a,arrays[5],label="5")
plt.plot(a,arrays[10],label="10")
plt.legend()
plt.show()
