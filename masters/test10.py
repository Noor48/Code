import numpy as np
import matplotlib.pyplot as plt
import math 
import cmath

s1 = 0
s2 = 0
a = []
b = []
c=[]
d=[]
e=[]
r = 11
T = 40
N = 10
def E(n, m):
    return (2*math.pi*(n-m))/(math.log(N))

def x(n, m):
    a = (1/1-(2j*math.pi*(n-m)/math.log(N)))/(math.sqrt(math.log(N)))
    b = (N**(1-(2j*math.pi*(n-m)/math.log(N)))-1)
    return a*b

for t in np.arange(0,1,0.001):
    C=0
    Z=0
    for n in range(0,r):
        s2=0    
        for m in range(0,r):
            s1=0
            for k in range(0,r):
                s1 += (1/2.0)*x(n,k)*x(k,m)*(E(k,m)*cmath.exp(1j*E(n,k)*t) - E(n,k)*cmath.exp(1j*E(k,m)*t))
            s2 += s1*np.conjugate(s1)
        Z += cmath.exp(-E(n,0)/T)
        C += (cmath.exp(-E(n,0)/T)*s2)
        if(n==1):
            c.append(C/Z)
        if(n==5):
            d.append(C/Z)
        if(n==5):
            e.append(C/Z)
    a.append(t)
    b.append(C/Z)
data = np.column_stack((a, b))
np.savetxt('test.dat', data , delimiter='  ')


plt.plot(a,b,label="n=10")
plt.plot(a,c,label="n=1")
plt.plot(a,d,label="n=2")
plt.plot(a,e,label="n=5")
plt.legend()
plt.show()