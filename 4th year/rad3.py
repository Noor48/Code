import matplotlib.pyplot as plt
import numpy as np
import math
import seaborn as sns

def f1(t, N):
    return -0.08*N

def f2(t,N):
    return N*math.exp(-0.08*t)
print("Enter initial particle number: ")
N0 = float(input())
print("Enter decay constant: ")
lam = float(input())
h=0.0001
t=0
dn=0
N=N0
x = []
y = []
z = []
j = []
k = []
l = []
for i in range(0,1000000,1):
    dn = -lam*N*h
#    N += dn
    N -= lam*N*h
    t += h
    x.append(t)
    y.append(math.log(N))
    z.append(math.log(math.fabs(dn)))
    j.append(N)
    k.append(dn)

m = ((y[1000]-y[100])/(x[1000]-x[100]))
print("Slope of the graph: ", m)
r = []
for i in range(0,1000000, 1):
    r.append(y[i]-5)
#print(r)
#print(q)
with open("rad2.dat", "w") as f:
    a = np.array(x)
    b = np.array(y)
    c = np.array(z)
    d = np.column_stack([a,b,c])
    np.savetxt(f,d, fmt='%1.4e')

plt.plot(x,y, label="N(t)")
plt.plot(x,z, label="dN(t)")
#plt.plot(x,r)
plt.legend()
plt.title('Radioactive Decay', fontsize=30)
plt.xlabel("t", fontsize=15)
plt.ylabel("N", fontsize=15)
plt.show()

plt.plot(x,y, label="N(t)")
plt.plot(x,z, label="dN(t)")
#plt.plot(x,r)
plt.legend()
plt.title('Radioactive Decay', fontsize=20)
plt.xlabel("t", fontsize=15)
plt.ylabel("N", fontsize=15)
plt.savefig('rad2.png')