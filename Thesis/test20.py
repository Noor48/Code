import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("IMAGCo.in",dtype=np.float64,skiprows=1) 
datas1=np.loadtxt("IMAGFe.in",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='lightcoral')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='purple', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.ylabel('Dielectric constant ' '$\epsilon$', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='violet')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='saddlebrown', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.ylabel('Dielectric constant ' '$\epsilon$', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.savefig("dielecimageng.svg")