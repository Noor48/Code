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

l =np.linspace(0,10,200)

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(b,c)
#plt.plot([1,1], [0,1])
plt.xlim(0,5.01)
plt.ylim(0,1.01)
plt.vlines(1,0,1,ls='--')
plt.xticks([1,5], ['$E/  \Lambda$','$\Lambda$'],fontsize='20')
plt.vlines(5,0,0.2,ls='--')
plt.hlines(0.2,0,5,ls='--')
plt.hlines(1,0,1,ls='--')
plt.yticks([0.2,1], ['$E/  \Lambda$','$\Lambda$'],fontsize='20')
plt.xlabel('x',fontsize=20)
plt.ylabel('p',fontsize=20)
plt.fill_between(b,c, color="skyblue",hatch='/', alpha=0.5)
plt.fill_between([0,1],[0,0],[1,1], color="skyblue",hatch='/', alpha=0.5)
plt.text(2, 0.6, 'xp = E', fontsize=20)
#ax.set_xticks([])
#ax.set_yticks([])
#ax.
plt.show()

l =np.linspace(0,10,200)
f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(b,c)
#plt.plot([1,1], [0,1])
plt.xlim(0,5.01)
plt.ylim(0,1.01)
plt.vlines(1,0,1,ls='--')
plt.xticks([1,5], ['$E/  \Lambda$','$\Lambda$'],fontsize='20')
plt.vlines(5,0,0.2,ls='--')
plt.hlines(0.2,0,5,ls='--')
plt.hlines(1,0,1,ls='--')
plt.yticks([0.2,1], ['$E/  \Lambda$','$\Lambda$'],fontsize='20')
plt.xlabel('x',fontsize=20)
plt.ylabel('p',fontsize=20)
plt.fill_between(b,c, color="skyblue",hatch='/', alpha=0.5)
plt.fill_between([0,1],[0,0],[1,1], color="skyblue",hatch='/', alpha=0.5)
plt.text(2, 0.6, 'xp = E', fontsize=20)
#ax.set_xticks([])
#ax.set_yticks([])
#ax.
plt.savefig("pic3.png")