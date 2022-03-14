import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("ENERGY_LOSSSPECTRUM.dat",dtype=np.float64,skiprows=1) 

fig, axs = plt.subplots(2,2,figsize=(10,8))
axs[0,0].plot(datas[:,0], datas[:,1], label='xx', color='orange')
axs[0,0].legend()
axs[0,1].plot(datas[:,0], datas[:,2], label='yy', color='blue')
axs[0,1].legend()
axs[1,0].plot(datas[:,0], datas[:,3], label='zz', color='red')
axs[1,0].legend()
fig.suptitle('Energyloss spectra', fontsize=20)
fig.supylabel('cm^-1',fontsize=10)
fig.supxlabel('Energy (eV)',fontsize=10)
fig.tight_layout()
plt.show()

fig, axs = plt.subplots(2,2,figsize=(10,8))
axs[0,0].plot(datas[:,0], datas[:,1], label='xx', color='orange')
axs[0,0].legend()
axs[0,1].plot(datas[:,0], datas[:,2], label='yy', color='blue')
axs[0,1].legend()
axs[1,0].plot(datas[:,0], datas[:,3], label='zz', color='red')
axs[1,0].legend()
fig.suptitle('Energyloss spectra', fontsize=20)
fig.supylabel('cm^-1', fontsize=10)
fig.supxlabel('Energy (eV)', fontsize=10)
fig.tight_layout()
plt.savefig("testenloss.png")
