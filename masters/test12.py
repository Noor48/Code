import numpy as np
import cmath

# Define the values of n you want to extract
n_values = [2, 5, 10, 20]

# Initialize the arrays for each n value
arrays = {n: [] for n in n_values}

# Existing code
r = 100  # Assuming r is defined somewhere
T = 1.0  # Assuming T is defined somewhere

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

# Save the arrays to separate files
for n, arr in arrays.items():
    filename = f'test_n{n}.dat'
    np.savetxt(filename, np.column_stack((np.arange(0, len(arr) * 0.001, 0.001), arr)), delimiter='  ')
