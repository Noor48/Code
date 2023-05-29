import numpy as np
import matplotlib.pyplot as plt
import math 
import cmath

a = [] #initialize some list to plot data
b = []
r=11    # matrix dimension number
N=10    #Higest interval in the spectrum
T=40    #temperature

#function for spetrum E_{nm}
def E(n, m):
    return (2*math.pi*(n-m))/(math.log(N))

#function for position x_{nm}
def x(n, m):
    a = (1/1-(2j*math.pi*(n-m)/math.log(N)))/(math.sqrt(math.log(N)))
    b = (N**(1-(2j*math.pi*(n-m)/math.log(N)))-1)
    return a*b

#calculating Thermal OTOC
for t in np.arange(0,1,0.001):
    Z=0  
    C=0 
    s3=0
    for n in range(0,r):
        s2 = 0
        for m in range(0,r):
            s1=0
            for k in range(0,r):
                s1 += (1/2.0)*x(n,k)*x(k,m)*(E(k,m)*cmath.exp(1j*E(n,k)*t) - E(n,k)*cmath.exp(1j*E(k,m)*t))
            s2 += s1*np.conjugate(s1)
    Z += cmath.exp(-E(n,0)/T)   #partition function
    C += (cmath.exp(-E(n,0)/T)*s2)  #e^{-\beta E_n} O
    s3=C/Z  #expectation value or Thermal OTOC
    a.append(t)
    b.append(s3)


#for plot
f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a, b, label='n=10', color='mediumvioletred')
plt.ylabel('$c_{n}(t)$',fontsize='xx-large')
plt.xlabel('t',fontsize='xx-large')
plt.legend()
plt.savefig('test.png')