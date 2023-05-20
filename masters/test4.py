import numpy as np 
import matplotlib.pyplot as plt
import math
from joblib import Parallel, delayed
x = 1
p = 1
a=[]
b=[]
c=[]
d=[]
s1=0
s2=0
s3=0
#t = np.linspace(0, 10, 100)
#x = x0 * np.exp(t)
#p = p0 * np.exp(-t)
for t in np.arange(0,10,0.001):
    s1 = x*np.exp(t)
    s2 = p*np.exp(-t)
    s3 = s2*s1
    b.append(s1)
    c.append(s2)
data = np.column_stack((b,c))
np.savetxt("test4.dat", data)    
plt.plot(b,c)
plt.xlim(0,6)
plt.show()