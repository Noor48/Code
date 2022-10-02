import numpy as np 
import matplotlib.pyplot as plt

a = np.loadtxt('t3.dat')

plt.plot(a[:,0], a[:,1])
plt.xlim([0,100])
plt.show()