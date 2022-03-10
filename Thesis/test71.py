import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np


datas1=np.loadtxt("TDOS.dat",dtype=np.float64,skiprows=1) 
datas2=np.loadtxt("PDOS_USER.dat",dtype=np.float64,skiprows=1) 

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
a1=datas1[:,0]
a2=datas1[:,1]
a3=datas1[:,2]
a4=datas2[:,0]
a5=datas2[:,1]
a6=datas2[:,2]
a7=datas2[:,3]
a8=datas2[:,4]
a9=datas2[:,5]
a10=datas2[:,6]
plt.imshow(a1, a2, label="up TDOS", cm.coolwarm)
plt.imshow(a1, a3, label="down TDOS", cm.coolwarm )
plt.imshow(a4, a5, label='up In all', cm.coolwarm )
plt.imshow(a4, a6, label='up In all', cm.coolwarm )
plt.imshow(a4, a7, label='up Fe all', cm.coolwarm )
plt.imshow(a4, a8, label='up In all', cm.coolwarm )
plt.imshow(a4, a9, label='up In all', cm.coolwarm )
plt.imshow(a4, a10, label='up In all', cm.coolwarm )
plt.colorbar()
plt.legend()
plt.title("Density of States", fontsize=20)
plt.xlabel("Energy (ev)", fontsize=10)
plt.xlabel("", fontsize=10)
plt.show()