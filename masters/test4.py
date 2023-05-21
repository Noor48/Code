import numpy as np 
import matplotlib.pyplot as plt
import math
from joblib import Parallel, delayed
x = 1
p = 1
b=[]
c=[]
s1=0
s2=0
s3=0
#t = np.linspace(0, 10, 100)
#x = x0 * np.exp(t)
#p = p0 * np.exp(-t)
for t in np.arange(0,10,0.001):
    s1 = x*np.exp(t)
    s2 = p*np.exp(-t)
    b.append(s1)
    c.append(s2)
plt.plot(b,c)
#plt.plot([1,1], [0,1])
plt.xlim(0,6)
plt.vlines(1,0,1)
plt.fill_between(b,0,c, color="skyblue", alpha=0.5)
plt.show()