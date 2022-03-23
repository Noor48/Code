import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("EXTINCTIONCo.dat")
data1 = np.loadtxt("EXTINCTIONFe.dat")

plt.plot(data[:,0], data[:,1], label="InCoO3", color='limegreen' , linestyle='-')
plt.plot(data1[:,0], data1[:,1], label="InFeO3", color='indigo' , linestyle='-.')
plt.xlim([0.2,25])
plt.xlabel("Energy (eV)",fontsize='large')
plt.ylabel("Energyloss",fontsize='large')
plt.legend()
plt.show()

plt.plot(data[:,0], data[:,1], label="InCoO3", color='limegreen' , linestyle='-')
plt.plot(data1[:,0], data1[:,1], label="InFeO3", color='indigo' , linestyle='-.')
plt.xlim([0.2,25])
plt.xlabel("Energy (eV)",fontsize='large')
plt.ylabel("Energyloss",fontsize='large')
plt.legend()
plt.savefig("enloss.png")