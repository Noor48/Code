import matplotlib.pyplot as plt
import numpy as np

a = np.loadtxt('t.dat')
plt.hist(a[:],bins='auto')
plt.show()