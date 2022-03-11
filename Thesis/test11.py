#!/usr/bin/python
# -*- coding:utf-8 -*-
import numpy as np
import matplotlib as mpl
mpl.use('Agg') #silent mode
from matplotlib import pyplot as plt
import matplotlib.ticker as ticker
import seaborn as sns
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
datas=np.loadtxt('REFORMATTED_BAND_DW.dat',dtype=np.float64,skiprows=1)

axe = plt.subplot(111)
axe.axhline(y=0, xmin=0, xmax=1,linestyle= '--',linewidth=0.5,color='0.5')
for i in xtick[1:-1]:
    axe.axvline(x=i, ymin=0, ymax=1,linestyle= '--',linewidth=0.5,color='0.5')
fmri = sns.load_dataset("REFORMATTED_BAND_DW.dat")
sns.lineplot(datas[:0],datas[:,1], hue='enevt')
plt.show()