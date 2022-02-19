import matplotlib.pyplot as plt
import numpy as np
import math
import random
import time

random.seed(time.time())
N=100000
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

print(a)

for i in range(-n,n,1):
    for j in range (0,N,1):
        if(i == a[j]):
            y+=1
    c.append(y)
print(len(c))
for i in range(0,2*n):
    z = c[i]/N
    p.append(z)
    t = i-n
    b.append(t)
print(len(p))
with open ("rad4.txt", "w") as f:
    n=np.array(p)
    m=np.array(b)
    d=np.column_stack([m,n])
    np.savetxt(f,d)

plt.plot(b,p)
plt.show()