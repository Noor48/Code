import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


# Define a few parameters for the integration
n_0 = 1E6 # Initial number of Potassium-40 nuclei
lam =  5.8E-11 # Decay constant in units of inverse years. 
total_time = 5E10 # Total time to run the integration in units of years.

# Define the time step for the integration. 
dt = 1E5

# Set up the time vector. We'll start from 0 going to the total time, taking
# steps of dt. For this, we will use the `arange` function in numpy. 
time_range = np.arange(0, total_time, dt)

# Set up the storage vector to keep track of the number of Potassium-40 nuclei
n_t = np.zeros(len(time_range))

# Set the initial condition. 
n_t[0] = n_0

# Begin the integration. Go from 0 to the total length - 1 so we can still
# compute the n_t[i + 1] value. 
for i in range(len(time_range) - 1):
    
    # Compute the change in the number of Potassium-40 nuclei
    dN = -lam * n_t[i] * dt
    
    # Update the current number in the storage vector. 
    n_t[i + 1] = n_t[i] + dN

# Convert our n_t to fractional abundance. 
K40_frac = n_t / n_0
Ar40_frac = 1 - K40_frac

# Plot our integration. 
plt.plot(time_range, K40_frac, '-', label='Potassium-40')
plt.plot(time_range, Ar40_frac, '-', label='Argon-40')
plt.xlabel('time (years)')
plt.ylabel('fractional abundance')
plt.legend()

# Evaluate the analytical solution. 
analytic_soln = n_0 * np.exp(-lam * time_range)
analytic_frac = analytic_soln / n_0

# Plot our numerical integration. 
plt.plot(time_range, K40_frac, '-', label='numerical integration')

# Plot the analytical solution as a dotted line.
plt.plot(time_range, analytic_frac, ':', label='analytical solution') 
plt.ylabel('fractional abundance')
plt.xlabel('time (years)')
plt.legend()


# Define the large time step.
bigstep = 5E9
timerange_bigstep = np.arange(0, total_time, bigstep)

# Perform the integration.
nt_bigstep = np.zeros(len(timerange_bigstep))
nt_bigstep[0] = n_0
for i in range(len(timerange_bigstep) - 1):
    dN = -lam * nt_bigstep[i] * bigstep
    nt_bigstep[i + 1] = nt_bigstep[i] + dN
    
# Convert the numbers to fractional abundance. 
K40_frac_bigstep = nt_bigstep / n_0

# Plot the solutions
plt.plot(time_range, K40_frac, '-', label='integration with $\Delta t = %s$ years'
         %dt)
plt.plot(timerange_bigstep, K40_frac_bigstep, '-',
         label='integration with $\Delta t= %G$ years' %bigstep)
plt.plot(time_range, analytic_frac, ':', label='analytical solution')

# Add axes labels and a legend. 
plt.xlabel('time (years)')
plt.ylabel('fractional abundance')
# plt.xlim([0.8E11, 1E11])
# plt.ylim([-.2, 0.2])
plt.legend()


# Let the large time step integration run even further. 
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