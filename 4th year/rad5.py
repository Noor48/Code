import matplotlib.pyplot as plt
import numpy as np
import random
import math
import time

random.seed(time.time()) 
N=500.0
n=N
nl=N
t=[]
nf=[]
nlf=[]
for i in range(0,10000):
    x=random.random()
    y=n/N
    if(x<=y):
        n-=1
    else:
        n+=1
    t.append(i)
    nf.append(n)

    nl+=1-(2*nl)/N
    nlf.append(nl)

with open("rad5.dat", "w") as f:
    a = np.array(t)
    b = np.array(nf)
    c = np.array(nlf)
    d = np.column_stack([a,b,c])
    np.savetxt(f,d)

plt.plot(a,b)
plt.plot(a,c)
plt.xlabel("T" , fontsize = 12)
plt.ylabel("nl", fontsize = 12)
plt.title("Particle diffusion at a time", fontsize = 20)
plt.show()

plt.plot(t,nf)
plt.plot(t,nlf)
plt.xlabel("T" , fontsize = 12)
plt.ylabel("nl", fontsize = 12)
plt.title("Particle diffusion at a time", fontsize = 20)
plt.legend()
plt.savefig("rad5.png")