import matplotlib.pyplot as plt
import numpy as np


datas1=np.loadtxt("TDOS1.dat",dtype=np.float64,skiprows=1) 
datas2=np.loadtxt("PDOS_USER1.dat",dtype=np.float64,skiprows=1)

datas3=np.loadtxt("TDOS2.dat",dtype=np.float64,skiprows=1) 
datas4=np.loadtxt("PDOS_USER2.dat",dtype=np.float64,skiprows=1)

fig, axs=plt.subplots(1,2,figsize=(10,8))

axs[0].plot(datas1[:,0], datas1[:,1], label="up TDOS", color='darkgreen', linewidth=1)
axs[0].plot(datas1[:,0], datas1[:,2], label="down TDOS", color='darkgreen', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,1], label='up In all', color='purple', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,2], label='up In all', color='purple', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,3], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,4], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,5], label='up O all', color='orange', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,6], label='up O all', color='orange', linewidth=1)
axs[0].legend()


axs[1].plot(datas3[:,0], datas3[:,1], label="up TDOS", color='darkviolet', linewidth=1)
axs[1].plot(datas3[:,0], datas3[:,2], label="down TDOS", color='darkviolet', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,1], label='up In all', color='forestgreen', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,2], label='up In all', color='forestgreen', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,3], label='up Co all', color='royalblue', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,4], label='up Co all', color='royalblue', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,5], label='up O all', color='slategrey', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,6], label='up O all', color='slategrey', linewidth=1)
axs[1].legend()

axs[0].title.set_text("InFeO3")
axs[1].title.set_text("InCoO3")
fig.suptitle("Density of States", fontsize=40)
fig.supxlabel("Energy (ev)", fontsize=20)
fig.supylabel("arbitrary", fontsize=20)
fig.tight_layout()
plt.show()

fig, axs=plt.subplots(1,2,figsize=(10,8))

axs[0].plot(datas1[:,0], datas1[:,1], label="up TDOS", color='darkgreen', linewidth=1)
axs[0].plot(datas1[:,0], datas1[:,2], label="down TDOS", color='darkgreen', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,1], label='up In all', color='purple', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,2], label='up In all', color='purple', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,3], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,4], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,5], label='up O all', color='orange', linewidth=1)
axs[0].plot(datas2[:,0], datas2[:,6], label='up O all', color='orange', linewidth=1)
axs[0].legend()


axs[1].plot(datas3[:,0], datas3[:,1], label="up TDOS", color='darkviolet', linewidth=1)
axs[1].plot(datas3[:,0], datas3[:,2], label="down TDOS", color='darkviolet', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,1], label='up In all', color='forestgreen', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,2], label='up In all', color='forestgreen', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,3], label='up Co all', color='royalblue', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,4], label='up Co all', color='royalblue', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,5], label='up O all', color='slategrey', linewidth=1)
axs[1].plot(datas4[:,0], datas4[:,6], label='up O all', color='slategrey', linewidth=1)
axs[1].legend()

axs[0].title.set_text("InFeO3")
axs[1].title.set_text("InCoO3")
fig.suptitle("Density of States", fontsize=40)
fig.supxlabel("Energy (ev)", fontsize=20)
fig.supylabel("arbitrary", fontsize=20)
fig.tight_layout()
plt.savefig("testdos.svg")