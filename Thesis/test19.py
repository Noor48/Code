import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("REALCo.in",dtype=np.float64,skiprows=1) 
datas1=np.loadtxt("REALFe.in",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)

plt.plot(datas[:,0], datas[:,1],linewidth=1.5, label='InCoO3', color='violet')
plt.plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='InFeO3', color='saddlebrown', ls='--')
#plt.title('Reflectivity', fontsize=20)
plt.xlim([0.2,20])
plt.axhline(0, c='dimgrey', linestyle='-.')
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
plt.xlim([0.2,20])
plt.axhline(0, c='dimgrey', linestyle='-.')
plt.ylabel('Dielectric constant ' '$\epsilon$', fontsize=10)
plt.xlabel('Energy (eV)', fontsize=10)
plt.legend()
plt.savefig("dieleceng.png")