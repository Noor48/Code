import matplotlib.pyplot as plt
import numpy as np
import math
import random
import time

random.seed(time.time())
#print("Enter trial number: ")
#N=int(input())
#print("Enter step number: ")
#n=int(input())
N=100000000
n=100
a = []
c = []
p = []
b = []
y = 0
z = 0
t = 0
for i in range(0,N):
    x=0
    r=random.randint(0,n)
    for _ in range(0,r):
        s = random.random()
        if(s>0.5):
            x+=1
        else:
            x-=1
    a.append(x)

#print(a)

for i in range(-n,n,1):
    y = 0
    for j in range (0,N,1):
        if(i == a[j]):
            y+=1
    c.append(y)
for i in range(0,2*n):
    z = c[i]/N
    p.append(z)
    t = i-n
    b.append(t)
with open ("rad4.txt", "w") as f:
    n=np.array(p)
    m=np.array(b)
    d=np.column_stack([m,n])
    np.savetxt(f,d)

plt.plot(b,p)
plt.xlabel("Numbers")
plt.ylabel("Probability")
plt.show()

plt.plot(b,p)
plt.xlabel("Numbers")
plt.ylabel("Probability")
plt.savefig("rad4.png")