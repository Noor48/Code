import matplotlib.pyplot as plt
import numpy as np
import math
import seaborn as sns

def f1(t, N):
    return -0.08*N

def f2(t,N):
    return N*math.exp(-0.08*t)

N0 = 1*pow(10,8)
h=0.0001
t=0
dn=0
N=N0
x = []
y = []
z = []
for i in range(0,1000000,1):
    dn = -0.08*N*h
    N += dn
    t += h
    x.append(t)
    y.append(N)
    z.append(f2(t,N0))

with open("rad2.txt", "w") as f:
    a = np.array(x)
    b = np.array(y)
    c = np.array(z)
    d = np.column_stack([a,b,c])
    np.savetxt(f,d)

plt.plot(x,y, label="dN=-0.08*n*dt")
plt.plot(x,z, label="N=N0exp(-0.08*t)")
plt.legend()
plt.title('Radiactive Decay', fontsize=20)
plt.xlabel("t", fontsize=15)
plt.ylabel("N0-dn", fontsize=15)
plt.show()

plt.plot(x,y, label="dN=-0.08*n*dt")
plt.plot(x,z, label="N=N0exp(-0.08*t)")
plt.legend()
plt.title('Radiactive Decay', fontsize=20)
plt.xlabel("t", fontsize=15)
plt.ylabel("N0-dn", fontsize=15)
plt.savefig('rad2.png')