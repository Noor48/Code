import matplotlib.pyplot as plt
import numpy as np 
import math

def f1(t,N):
    return -0.08*N


h=0.001
x = []
y = []
z = []
t = 0
N0 = 1*pow(10,8)
N = N0
k1 = 0
k2 = 0
k3 = 0
k4 = 0
dN = 0
for i in range(0,100000,1):
    x.append(t)
    y.append(N)
    z.append(N0 - N)
    k1 = h*f1(t,N)
    k2 = h*f1(t+h/2, N+k1/2)
    k3 = h*f1(t+h/2, N+k2/2)
    k4 = h*f1(t+h, N+k3)

    N += (k1 +2*k2 + 2*k3 + k4)/6
    t += h

with open("p4.dat", "w") as f:
    a = np.array(x)
    b = np.array(y)
    c = np.array(z)
    d = np.column_stack([a,b,c])
    np.savetxt(f, d)
plt.plot(x ,y, label="line 1")
plt.plot(x,z, label="line 2")
plt.legend()
plt.title('Radioactive decay', fontsize = 20)
plt.xlabel('T', fontsize = 15)
plt.ylabel('N' , fontsize = 15)
plt.show()

plt.plot(x ,y, label="line 1")
plt.plot(x,z, label="line 2")
plt.title('Radioactive decay', fontsize = 20)
plt.xlabel('T', fontsize = 15)
plt.ylabel('N' , fontsize = 15)
plt.legend()
plt.savefig('p4.png')