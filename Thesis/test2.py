import matplotlib.pyplot as plt
import numpy as np


datas=np.loadtxt("ABSORPTION_2D.dat",dtype=np.float64,skiprows=1) 

fig, axs = plt.subplots(2,figsize=(10,8))
axs[0].plot(datas[:,0], datas[:,1], linewidth=1.0, label='xx', color='orange')
axs[0].legend()
axs[1].plot(datas[:,0], datas[:,2], linewidth=1.0, label='yy', color='blue')
axs[1].legend()
#fig.suptitle('Absorption', fontsize=40)
fig.supylabel('Absorption (cm^-1)', fontsize=20)
fig.supxlabel('Energy (eV)', fontsize=20)
fig.tight_layout()
plt.show()

fig, axs = plt.subplots(2,figsize=(10,8))
axs[0].plot(datas[:,0], datas[:,1], linewidth=1.0, label='xx', color='orange')
axs[0].legend()
axs[1].plot(datas[:,0], datas[:,2], linewidth=1.0, label='yy', color='blue')
axs[1].legend()
#fig.suptitle('Absorption', fontsize=40)
fig.supylabel('Absoption (cm^-1)', fontsize=20)
fig.supxlabel('Energy (eV)', fontsize=20)
fig.tight_layout()
plt.savefig("testabs2d.svg")
