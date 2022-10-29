# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 10:10:10 2022

@author: radun
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import cosine, uniform, beta,norm

#%%

note = np.array([10,10,9,5,6,7,2,8,7,7,7,6,5,2,3,10])

plt.figure()
plt.hist(note, bins=50)


#%%
N = 10000
a=1
b=4
x= cosine.rvs(size = N)
plt.hist(x,density=True,alpha=0.5,bins=100)

xd=np.linspace(-np.pi,np.pi,1000)
plt.plot(xd, cosine.pdf(xd))

#%%


N = 10000
a=20
b=15
x= beta.rvs(a,b,size = N)
plt.hist(x,density=True,alpha=0.5,bins=100)

xd=np.linspace(0,1,1000)
plt.plot(xd, beta.pdf(xd,a,b))


#%%

N = 10000
x= norm.rvs(0,1,size = N)

plt.hist(x,density=True,alpha=0.5,bins=100)

xd=np.linspace(-10,10,1000)
plt.plot(xd, norm .pdf(xd,0,1))

#%%
N=10000
B=np.zeros(N)
T=np.zeros(N)
P=0
C=0

print(2)
for i in range(N):
    B[i]= 1*(np.random.rand()<0.02)
    test=0
    
    if B[i]==1:
        test = 1*(np.random.rand()<0.98)
    else:
        #sanatos
        test = 1*(np.random.rand()<0.05)
        
        
    P+= (1*(B[i]==1)*(1*(test==1)))
    C+= (1*(test==1))
    
    
print(P/C)

