import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("TRANSMISSION_2D.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], linewidth=1.5, label='xx', color='darkslateblue')
plt.plot(datas[:,0], datas[:,2], linewidth=1.5, label='yy', color='lightcoral', linestyle='-.')
plt.legend()
plt.title("Transmission", fontsize=20)
plt.ylabel('Transmission (cm^-1)', fontsize=10)
plt.xlabel('Photon Energy, E (eV)', fontsize=10)
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], linewidth=1.5, label='xx', color='darkslateblue')
plt.plot(datas[:,0], datas[:,2], linewidth=1.5, label='yy', color='lightcoral', linestyle='-.')
plt.legend()
plt.title("Transmission", fontsize=20)
plt.ylabel('Transmission (cm^-1)', fontsize=10)
plt.xlabel('Photon Energy, E (eV)', fontsize=10)
plt.savefig('test10tr.svg')
