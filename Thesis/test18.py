import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("REFLECTIVITYCo.dat",dtype=np.float64,skiprows=1) 
datas1=np.loadtxt("REFLECTIVITYFe.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='darkseagreen')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='darkslategrey', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.ylabel('Reflectivity R', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='darkseagreen')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='darkslategrey',ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.ylabel('Reflectivity R', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.savefig("refleceng.svg")