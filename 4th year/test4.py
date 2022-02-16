import matplotlib.pyplot as plt 
import numpy as np
import math 

def f1(S,T):
  #  N=1*(10**3), V=100, m=9.1*pow(10,-31), k=1.38*pow(10, -23), h=6.634*pow(10,-34)
    return math.log((100/1*(10**3))*pow((2*math.pi*9.1*pow(10,-31)*1.38*pow(10, -23)*T/(6.634*pow(10,-34)/2)),(3/2)) +(5/2))
x = []
y = []
z = []
with open("test4.txt", "w") as f:  
  for i in range(0,2,1):
    T = 0 
    S = 0
    x.append(T)
    y.append(f1(T,S))
    T = T+0.001
    S += S+f1(T,S)
    splitted = x.split(" ")
    z.append(slittes[x], splitted[y])
  f.write(z)
#  a = np.array(x)
#  b = np.array(y)
#  data = np.column_stack((x, y))
#  f = np.savetxt=("~/Project/test4.txt", data)

#print(x +"  " + y) 
plt.plot(x,y)
plt.show()