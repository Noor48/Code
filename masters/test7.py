import numpy as np 
import matplotlib.pyplot as plt

a = np.loadtxt("BRET.DAT")

fig, ax = plt.subplots()

plt.plot(a[:,0], a[:,1], label="line 1")
ax.annotate('local max', xy=(2, 1), xytext=(3, 1.5),
            arrowprops=dict(facecolor='black', shrink=0.05))
plt.plot(a[:,0], a[:,2], label="line 2")
ax.annotate('local min', xy=(6, 1), xytext=(6, 10),
            arrowprops=dict(facecolor='black', shrink=0.05))
plt.legend()
plt.show()