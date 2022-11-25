# -*- coding: utf-8 -*-
"""
Created on Fri Nov 11 11:33:25 2022

@author: radun
"""

import matplotlib.pyplot as plt
import math
import numpy as np
import bisect

#%%

# am 700  de potentialiangajati
# sansa de a fi angajat e 0.03
# care e sansa sa fie angajati cel putin 10 oameni

N = 1000
candidati = 700
p = 0.03

C = 0;

for i in range (N):
    c = 0
    for a in range(700):
        x = np.random.rand();
        c += 1*(x<=p)
    
    if c >=10:
        C+=1
    
print("probabilitatea este: ", C/N)

#%%

# probabilitate calculata

N = 1000
candidati = 700
p = 0.03

prob = 0
for i in range(10, candidati+1):

    prob += math.comb(candidati, i) * (p ** i) * ((1 - p) ** (candidati - i))
    
print("probabilitatea este: ", prob)  
    