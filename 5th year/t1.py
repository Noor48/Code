import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt('t9.dat')

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1])
plt.xlim([0,200])
plt.xlabel('iterations', fontsize=20)
plt.ylabel('<H>', fontsize=20)
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1])
plt.xlim([0,200])
plt.xlabel('iterations', fontsize=20)
plt.ylabel('<H>', fontsize=20)
plt.savefig('Hmc.pdf')