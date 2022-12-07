# -*- coding: utf-8 -*-
"""
Created on Fri Nov 18 10:23:42 2022

@author: radun
"""


import matplotlib.pyplot as plt
import math
import numpy as np
import scipy


#%%

N =  100000
n = 100
p =1/2
bin = np.random.geometric(p, N);
plt.hist(bin, bins=100)

#%%
# N generari pentru 
N =  1000
n = 100
p =1/2
bin = []
for j in range (N):
    u = np.random.rand()
    x = math.ceil(math.log(u)/math.log(1-p))
    bin.append(x)
    
    
plt.hist(bin, bins=100)



#%%

k = 5
p = 1/2

# Sansa de a fi incompatibil cu cel putin k va fi sansa de a fi incompatibil cu 1 + sansa de a fi incompatibil cu 2 + ... etc 


S = 0
for i in range(1, k+1):
    S += (1-p)**(i-1) * p

print("Sansa de a fi incompatibil cu", k , "donatori este: ", (1-S))

#%%

n = 1000
N = 100000
l = 150
bin1 = []
bin2 = []
for i in range (N):
    x1 = np.random.binomial(n, l/n)
    x2 = np.random.poisson(l)
    bin1.append(x1)
    bin2.append(x2)

plt.hist(bin1, bins=100)
plt.hist(bin2, bins=100)


#%% ex5
l = 150
p = scipy.stats.poisson.cdf(l, 150)
print (1-p)

#%% bonus


n = 10000
pasi = 100
pas = 20
p = 1/2
bin = []
for _ in range (n):
    dist = 0
    for i in range (pasi):
        x= np.random.rand()
        if x < p:
            dist +=pas
        else:
            dist -=pas
            
    bin.append(dist)
    
plt.hist(bin, bins=100)
    

