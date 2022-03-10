import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("ABSORPTION_2D.dat",dtype=np.float64,skiprows=1) 

plt.plot(datas[:,0], datas[:,1], linewidth=1.0, label='xx', color='orange')
plt.plot(datas[:,0], datas[:,2], linewidth=1.0, label='yy', color='blue', linestyle='-.')
plt.legend()
plt.ylabel('Absoption (cm^-1)', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.show()


plt.plot(datas[:,0], datas[:,1], linewidth=1.0, label='xx', color='orange')
plt.plot(datas[:,0], datas[:,2], linewidth=1.0, label='yy', color='blue', linestyle='-.')
plt.legend()
plt.ylabel('Absoption (cm^-1)', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.savefig('testabs2dm.svg')