import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("REAL_OPTICAL_CONDUCTIVITY_2DCo.dat",dtype=np.float64,skiprows=1) 
datas1=np.loadtxt("REAL_OPTICAL_CONDUCTIVITY_2DFe.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='lightcoral')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='purple', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.xlim([0,90])
plt.axhline(0, c='dimgrey', linestyle='-.')
plt.ylabel('Optical conductivity ' '$\sigma$', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='lightcoral')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='purple', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.xlim([0,90])
plt.axhline(0, c='dimgrey', linestyle='-.')
plt.ylabel('Optical conductivity ' '$\sigma$', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.savefig("opcondrealev.png")