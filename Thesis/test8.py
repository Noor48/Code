import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("REAL_OPTICAL_CONDUCTIVITY_2D.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], linewidth=1.5, label='xx', color='slateblue')
plt.plot(datas[:,0], datas[:,2], linewidth=1.5, label='yy', color='lightcoral', linestyle='-.')
plt.legend()
plt.title("Real Optical Conductivity", fontsize=20)
plt.ylabel('Optical Conductivity,' '$\sigma$'  ' (1/fs)', fontsize=10)
plt.xlabel('Photon Energy, E (eV)', fontsize=10)
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], linewidth=1.5, label='xx', color='slateblue')
plt.plot(datas[:,0], datas[:,2], linewidth=1.5, label='yy', color='lightcoral', linestyle='-.')
plt.legend()
plt.title("Real Optical Conductivity", fontsize=20)
plt.ylabel('Optical Conductivity,' '$\sigma$'  ' (1/fs)', fontsize=10)
plt.xlabel('Photon Energy, E (eV)', fontsize=10)
plt.savefig('test8ro.svg')
