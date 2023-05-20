import numpy as np 
import matplotlib.pyplot as plt
import math
from joblib import Parallel, delayed
x = 1
p = 1
a=[]
b=[]
s1=0
s2=0
#t = np.linspace(0, 10, 100)
#x = x0 * np.exp(t)
#p = p0 * np.exp(-t)
for t in np.arange(0,10,0.001):
    s1 += x*np.exp(t)
    s2 += p*np.exp(-t)
    a.append(s1)
    b.append(s2)    
plt.plot(a,b)
plt.show()