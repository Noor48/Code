import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("ABSORPTIONFe.dat",dtype=np.float64,skiprows=1) 
datas1=np.loadtxt("ABSORPTIONCo.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], label='InFeO3', color='mediumvioletred')
plt.plot(datas1[:,0], datas1[:,1], label='InCoO3', color='teal', ls='--')
#plt.title('Absorption', fontsize=20)
plt.xlim([0,85])
plt.axhline(0, c='dimgrey', linestyle='-.')
plt.ylabel('Absorption' '$\ alpha$'', cm^-1',fontsize='large')
plt.xlabel('Energy (eV)',fontsize='large')
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(datas[:,0], datas[:,1], label='InFeO3', color='mediumvioletred')
plt.plot(datas1[:,0], datas1[:,1], label='InCoO3', color='teal', ls='--')
#plt.title('Absorption', fontsize=20)
plt.xlim([0,85])
plt.axhline(0, c='dimgrey', linestyle='-.')
plt.ylabel('Absorption' '$\ alpha$'', cm^-1',fontsize='large')
plt.xlabel('Energy (eV)',fontsize='large')
plt.legend()
plt.savefig("Absorptioneng.png")
