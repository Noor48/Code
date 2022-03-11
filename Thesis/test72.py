import matplotlib.pyplot as plt
import numpy as np


datas1=np.loadtxt("TDOS.dat",dtype=np.float64,skiprows=1)
datas2=np.loadtxt("PDOS_USER.dat",dtype=np.float64,skiprows=1)
 

fig, axs = plt.subplots(3,2,figsize=(10,8))
axs[0,0].plot(datas1[:,0], datas1[:,1],linewidth=1.5, label='xx', color='orange')
axs[0,0].legend()
axs[0,1].plot(datas1[:,0], datas1[:,2],linewidth=1.5, label='yy', color='blue')
axs[0,1].legend()
axs[1,0].plot(datas2[:,0], datas2[:,3],linewidth=1.5, label='zz', color='red')
axs[1,0].legend()
axs[1,1].plot(datas2[:,0], datas2[:,4],linewidth=1.5, label='xy', color='green')
axs[1,1].legend()
axs[2,0].plot(datas2[:,0], datas2[:,5],linewidth=1.5, label='yz', color='black')
axs[2,0].legend()
axs[2,1].plot(datas2[:,0], datas2[:,6],linewidth=1.5, label='zx', color='violet')
axs[2,1].legend()
fig.suptitle('Density Of states', fontsize=20)
fig.supylabel('cm^-1', fontsize=10)
fig.supxlabel('Energy (eV)', fontsize=10)
fig.tight_layout()
plt.show()