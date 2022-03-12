#!/usr/bin/python
# -*- coding:utf-8 -*-
import numpy as np
import matplotlib as mpl
mpl.use('Agg') #silent mode
from matplotlib import pyplot as plt
import matplotlib.ticker as ticker
import matplotlib.cm as cm
import seaborn as sns
import matplotlib.colors as mcolors
#------------------ FONT_setup ----------------------
font = {'family' : 'arial', 
    'color'  : 'black',
    'weight' : 'normal',
    'size' : 13.0,
    }

#------------------- Data Read ----------------------
Greek_alphabets=['Alpha','Beta','Gamma','Delta','Epsilon','Zeta','Eta','Theta', 'Iota','Kappa','Lambda','Mu','Nu','Xi','Omicron','Pi','Rho','Sigma','Tau','Upsilon','Phi','Chi','Psi','Pega']
group_labels=[];xtick=[]
with open('KLABELS','r') as reader:
    lines=reader.readlines()[1:]
for i in lines:
    s=i.encode('utf-8')#.decode('latin-1')
    if len(s.split())==2 and not s.decode('utf-8','ignore').startswith('*'):
        klabel=str(s.decode('utf-8','ignore').split()[0])
        for j in range(len(Greek_alphabets)):
            if (klabel.find(Greek_alphabets[j].upper())>=0):
                latex_exp=r''+'$\\'+str(Greek_alphabets[j])+'$'
                klabel=klabel.replace(str(Greek_alphabets[j].upper()),str(latex_exp))
        if (klabel.find('_')>0):
           n=klabel.find('_')
           klabel=klabel[:n]+'$'+klabel[n:n+2]+'$'+klabel[n+2:]
        group_labels.append(klabel)
        xtick.append(float(s.split()[1]))
datas=np.loadtxt('REFORMATTED_BAND_UP.dat',dtype=np.float64)

#--------------------- PLOTs ------------------------
fig, axe = plt.subplots(figsize=(1,111))
axe.axhline(y=0, xmin=0, xmax=1,linestyle= '--',linewidth=0.5,color='0.5')
for i in xtick[1:-1]:
    axe.axvline(x=i, ymin=0, ymax=1,linestyle= '--',linewidth=0.5,color='0.5')
n=28
colors = plt.cm.plasma(np.linspace(0, 1, n))
normalize = mpl.colors.Normalize(vmin=-1, vmax=1)
for i in range(1,n):
    t=axe.plot(datas[:,0], datas[:,i],lw=1, color=colors[i])
    #fig.colorbar(cm.ScalarMappable(norm=normalize, cmap=colors), ax=ax)
#axe.plot(datas[:,0],datas[:,1:],linewidth=1.0,color=colormaps)
axe.set_ylabel(r'$\mathrm{E}-\mathrm{E_F}$ (eV)',fontdict=font)
axe.set_xticks(xtick)
plt.title('Band Gap Up')
#plt.legend('$\downarrow$')
plt.yticks(fontsize=font['size']-2,fontname=font['family'])
axe.set_xticklabels(group_labels, rotation=0,fontsize=font['size']-2,fontname=font['family'])
axe.set_xlim((xtick[0], xtick[-1]))
plt.ylim(( -15,  10)) # set y limits manually
fig = plt.gcf()
fig.set_size_inches( 8, 6)
plt.savefig('test.png',dpi= 300)


datas1=np.loadtxt("TDOS.dat",dtype=np.float64,skiprows=1) 
datas2=np.loadtxt("PDOS_USER.dat",dtype=np.float64,skiprows=1)

fig, axs=plt.subplots(4, sharex='col', sharey='row', figsize=(10,8))

axs[0].plot(datas1[:,0], datas1[:,1], label="up TDOS", color='darkgreen', linewidth=1)
axs[0].axhline(0, c='black', alpha=0.3, linestyle='--')
axs[0].plot(datas1[:,0], datas1[:,2], label="down TDOS", color='darkgreen', linewidth=1)
axs[1].plot(datas2[:,0], datas2[:,1], label='up In all', color='purple', linewidth=1)
axs[1].axhline(0, c='black', alpha=0.3, linestyle='--')
axs[1].plot(datas2[:,0], datas2[:,2], label='up In all', color='purple', linewidth=1)
axs[2].plot(datas2[:,0], datas2[:,3], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[2].axhline(0, c='black', alpha=0.3, linestyle='--')
axs[2].plot(datas2[:,0], datas2[:,4], label='up Fe all', color='cornflowerblue', linewidth=1)
axs[3].plot(datas2[:,0], datas2[:,5], label='up O all', color='orange', linewidth=1)
axs[3].plot(datas2[:,0], datas2[:,6], label='up O all', color='orange', linewidth=1)
axs[3].axhline(0, c='black', alpha=0.3, linestyle='--')
axs[0].legend()
axs[1].legend()
axs[2].legend()
axs[3].legend()
fig.suptitle("Density of States", fontsize=40)
fig.supxlabel("Energy (ev)", fontsize=20)
fig.supylabel("arbitrary", fontsize=20)
fig.tight_layout()
plt.subplots_adjust(hspace=.0)
plt.savefig("test1.png")





'''
x1 = [0, 0.02, 0.04, 0.08, 0.12, 0.16, 0.2]
y1 = [0.0005, 0.052, 0.0905, 0.1675, 0.2485, 0.3225, 0.4035]

fig,ax=plt.subplots(figsize=plt.rcParams["figure.figsize"][::-1])
fig.subplots_adjust(left=0.1, right=0.875, top=0.9,bottom=0.125)

ax.scatter(y1, x1)

ax.set_ylabel("x", rotation=90)
ax.yaxis.tick_right()
ax.yaxis.set_label_position("right")
ax.set_xlabel("y", rotation=180)
ax.invert_xaxis()

plt.setp(ax.get_xticklabels(), rotation=90, va="top", ha="center")
plt.setp(ax.get_yticklabels(), rotation=90, va="center", ha="left")

ax.text(-0.05,0.5,"y-x scatter", ha="center", va="center",
        transform=ax.transAxes, rotation=90)


plt.show()
'''