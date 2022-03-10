import matplotlib.pyplot as plt
import numpy as np
import math

'''N0=1E13
#lam=0.08
#N=N0
#h=0.001
#t=0
#dn=0
#x=[]
#y=[]
#z=[]
#for i in range(0,100000,1):
#    dn = -lam*N*h
#    N -= lam*N*h
#    t += h
#    x.append(t)
#    y.append(math.log(N))
#    z.append(math.log(math.fabs(dn)))

#with open ("rad6.dat", "w") as f:
#    a = np.array(x)
#    b = np.array(y)
#    c = np.array(z)
#    d = np.column_stack([a,b,c])
#    np.savetxt(f,d)
'''

n_0 =1E6
lam = 5.8E-11
total_time = 5E13
dt = 1E11
time_range = np.arange(0, total_time, dt)
n_t = np.zeros(len(time_range))
n_t[0] = n_0
for i in range(len(time_range) - 1):
    dN = -lam*n_t[i]*dt
    n_t[i+1] = n_t[i] + dN
K40_frac = n_t/n_0
Ar40_frac = 1- K40_frac
'''
plt.plot(x,y)
plt.plot(x,z)
plt.show()
'''
plt.plot(time_range, K40_frac, '-', label="Potassium-40")
plt.plot(time_range, Ar40_frac, '-', label="Argon-40")
plt.xlabel('time (years)')
plt.ylabel('fractional abundance')
plt.legend()
plt.show()

long_time = 1E13
bigstep = 1E11  # Make an even bigger step
timerange_bigstep = np.arange(0, long_time, bigstep)

# Perform the integration.
nt_bigstep = np.zeros(len(timerange_bigstep))
nt_bigstep[0] = n_0
for i in range(len(timerange_bigstep) - 1):
    dN = -lam * nt_bigstep[i] * bigstep
    nt_bigstep[i + 1] = nt_bigstep[i] + dN
    
# Convert the numbers to fractional abundance. 
K40_frac_bigstep = nt_bigstep / n_0

# Plot it!
plt.plot(timerange_bigstep, K40_frac_bigstep, '-')
plt.xlabel('time (years)')
plt.ylabel('fractional abundance')
plt.show()
