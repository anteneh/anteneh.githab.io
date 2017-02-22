"""
Demo of the errorbar function, including upper and lower limits
"""
import numpy as np
import matplotlib.pyplot as plt

x = [32,64,96,128,160]

vmin05 = [0.416,0.428,0.436,0.441,0.445]
vmin06 = [0.45,0.452,0.46,0.468,0.472]
vmin07 = [0.51,0.53,0.55,0.56,0.56]
vmin08 = [0.57,0.575,0.578,0.58,0.58]

fp05 = [0.033,0.035,0.039,0.051,0.066]
fp06 = [0.023,0.028,0.032,0.035,0.036]
fp07 = [0.018,0.021,0.024,0.026,0.028]
fp08 = [0.012,0.013,0.014,0.016,0.017]

ls = 'dotted'
my_xticks = ['32','64','128','256','512']
fig = plt.figure(figsize=(12,9))
ax = fig.add_subplot(1, 1, 1)
plt.locator_params(axis='x',nbins=7)
ax.set_xticklabels((0,48,60,90,130,200,340,512,),fontsize=15)
#plt.xticks(x,my_xticks)

#ploting worstcase minimum vdds for different operating voltages
lns1 = ax.plot(x, vmin05, marker='x', ms=10, linestyle='-', color='r', linewidth=3, label='V$_{min_{0.5V}}$')
lns2 = ax.plot(x, vmin06, marker='*', ms=10, linestyle='--', color='c', linewidth=3, label='V$_{min_{0.6V}}$')
lns3 = ax.plot(x, vmin07, marker='^', ms=10, linestyle=':', color='b', linewidth=3, label='V$_{min_{0.7V}}$')
lns4 = ax.plot(x, vmin08, marker='s', ms=10, linestyle='-.', color='m', linewidth=3, label='V$_{min_{0.8V}}$')

#mirroring y2 axis
ax2 = ax.twinx()

lns5 = ax2.plot(x, fp05, marker='o', ms=10, linestyle='-', color='r', linewidth=3, label='FP$_{0.5V}$')
lns6 = ax2.plot(x, fp06, marker='p', ms=10, linestyle='--', color='c', linewidth=3, label='FP$_{0.6V}$')
lns7 = ax2.plot(x, fp07, marker='h', ms=10, linestyle=':', color='b', linewidth=3, label='FP$_{0.7V}$')
lns8 = ax2.plot(x, fp08, marker='d', ms=10, linestyle='-.', color='m', linewidth=3, label='FP$_{0.8V}$')
#set_xticklabels(xticklabels, fontsize=7)
#ax2.plot(x, wback, marker='^', ms=8,  color='cyan',label='Wback')
ax.set_xlabel('Block size in Bytes',fontsize=15)
ax.set_ylabel('Scalable voltage in [V] ',fontsize=15)
ax2.set_ylabel('Failure probability (log) ',fontsize=15)
#ax.set_xlim((0, 1.0))
ax.set_ylim((0.4, 0.6))
#newlabels=[item.get_text() for item in ax.get_yticklabels()]
#newlabels[0] = '$10^{-7}$'
#newlabels[1] = '$10^{-6}$'
#newlabels[2] = '$10^{-5}$'
#newlabels[3] = '$10^{-4}$'
#newlabels[4] = '$10^{-3}$'
#newlabels[5] = '$10^{-2}$'
#newlabels[6] = '$10^{-1}$'
#newlabels[7] = '$10^{0}$'
#newlabels[8] = '$10^{1}$'
#ax.set_yticklabels(newlabels, fontsize=20)
ax2.set_yticklabels(('',-1.9,-1.78,-1.65,-1.52,-1.39,-1.3,-1.22,-1.15,0), fontsize=15)
#ax.set_title('Errorbar upper and lower limits')
#ax.grid()
ax.yaxis.grid()
lns=lns1+lns2+lns3+lns4+lns5+lns6+lns7+lns8
labs=[l.get_label() for l in lns]
ax.legend(lns, labs, ncol=2,fontsize=15,columnspacing=1)
#ax.legend (ncol=2,fontsize=15,columnspacing=1)
#ax2.legend (ncol=2,fontsize=15,columnspacing=1)
#plt.savefig('voltageandfplog.pdf')
plt.show()
