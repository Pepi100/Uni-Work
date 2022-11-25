# -*- coding: utf-8 -*-
"""
Created on Fri Nov 11 10:06:03 2022

@author: radun
"""

import matplotlib.pyplot as plt
import math
import numpy as np
import bisect

#%%

N =  100000
n = 10
p =1/2
bin = np.random.binomial(n, p, N);
plt.hist(bin, bins=100)


#%%
#ex1 a
N = 100000
n = 10
p = 1/2
probab = [0] * (n+1)


final = []
for i in range(n+1):

    prob = math.comb(n, i) * (p ** i) * ((1 - p) ** (n - i))
    
    if i > 0 :
        probab[i] = probab[i-1] + prob 
    else:
        probab[i] = prob

for i in range(N):
    x = np.random.rand()
    poz = bisect.bisect_left(probab, x)
    final.append(poz)

plt.hist(final, bins=100)



#%%
#ex1 b
N = 100000
n = 10
p = 1/2
probab = [0] * (n*1)
bin = []
for i in range (N):
    c= 0
    for j in range (n):
        x = np.random.rand();
        c += 1*(x<=p)
        
    bin += [c]

plt.hist(bin, bins=100)
