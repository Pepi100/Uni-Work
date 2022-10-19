# -*- coding: utf-8 -*-
"""
Created on Fri Oct  7 09:49:09 2022

@author: Andreea Grecu
"""

import matplotlib.pyplot as plt
import numpy as np

#%% Problema 1

plt.figure()
plt.ylim([0,1])

N = 1000


H_prob=0.5
H=0
T=0


#Aruncarea cu o moneda clasica
for i in range(N):
    alegere = np.random.rand()
    if alegere <= H_prob :
        H+=1
    else:
        T+=1
    
    if i%10 == 0 and i!=0 :
        plt.plot(i, H/i, '.')
        
        

print("Probabilitatea finala sa pice Head= " , H/N)
    
#%% Problema 2

probabilitati =[0]+ [1/6]*6

#probabilitati = [0,0.25, 0.25, 0.2, 0.15, 0.1, 0.5]

N = 1000
numere=[0]*7


for i in range(1,len(probabilitati)):
    probabilitati[i] = probabilitati[i-1]+probabilitati[i]
    
print(probabilitati)


for i in range(N):
    alegere = np.random.rand()
    for j in range(1, 7):
        if alegere >= probabilitati[j-1] and alegere < probabilitati[j] :
            numere[j] += 1
            
print(numere)


#%% Problema 3

N = 10000
p=0

aruncari = 20


for j in range(N):
    reusite=0
    consecutive=0
    for i in range(aruncari):
        alegere = np.random.rand()
        if alegere <= 0.5 :
            consecutive += 1
        else:
            consecutive = 0
        if consecutive >= 4:
            reusite = 1
    p += reusite
    
print("Probabilitatea sa avem o secventa de 4 consecutive: ", p/N)


#%% Problema 4

verde = [3,3,3,3,3,6]
rosu = [1,4,4,4,4,4]
negru = [2,2,2,5,5,5]


#testam care zar ar trebui ales atunci cand alegi primul

N = 10000

#daca primul alege rosu
#am luat pentru player 2 maximul dintre negru si verde pentru 
crosu=0
for i in range(N):
    p1 = rosu[np.random.randint(6)]
    p2 = max(negru[np.random.randint(6)],verde[np.random.randint(6)])
    
    if p1>p2:
        crosu +=1;
        
print("Sansa minima de castig a primului daca alege zarul rosu: ", crosu/N);

cnegru=0
for i in range(N):
    p1 = negru[np.random.randint(6)]
    p2 = max(rosu[np.random.randint(6)],verde[np.random.randint(6)])
    
    if p1>p2:
        cnegru +=1;
        
print("Sansa minima de castig a primului daca alege zarul negru: ", cnegru/N);


cverde=0
for i in range(N):
    p1 = verde[np.random.randint(6)]
    p2 = max(rosu[np.random.randint(6)],negru[np.random.randint(6)])
    
    if p1>p2:
        cverde +=1;
        
print("Sansa minima de castig a primului daca alege zarul verde: ", cverde/N);


zaruri = [[1, 4, 4, 4, 4, 4], [3, 3, 3, 3, 3, 6], [2, 2, 2, 5, 5, 5]]

castig=0
for i in range(N):
    alegere1 = np.random.randint(3)
    zarP1 = zaruri[alegere1]
    
    zarRamas = zaruri[:alegere1] + zaruri[alegere1:]
    alegere2 = np.random.randint(2)
    zarP2 = zarRamas[alegere2]
    
    if (zarP1[np.random.randint(6)] > zarP2[np.random.randint(6)]):
        castig += 1
        
print("Sansele de castig ale primului daca amandoi aleg total random", castig / N)