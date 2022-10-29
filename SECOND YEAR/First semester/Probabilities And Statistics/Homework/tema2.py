# -*- coding: utf-8 -*-
"""
Created on Sat Oct 29 14:28:06 2022

@author: radun
"""


import numpy as np


#%% Probabilitatea sa aiba boala cu un test pozitiv
N=10000

P=0
C=0

for i in range(N):
    
    #alegem o persoana 
    B= 1*(np.random.rand()<0.02)
    test=0
    
    if B==1:
        test = 1*(np.random.rand()<0.98)
    else:
        #sanatos
        test = 1*(np.random.rand()<0.05)
        
        
    P+= (1*(B==1)*(1*(test==1)))
    C+= (1*(test==1))
    
    
print(P/C)


#%% Probabilitatea sa aiba boala cu doua teste pozitive
N=100000

P=0
C=0


for i in range(N):
    
    #alegem o persoana 
    B= 1*(np.random.rand()<0.02)
    
    if B==1:
        #bolnav
        test = 1*(np.random.rand()<0.98)
        test2 = 1*(np.random.rand()<0.98)
    else:
        #sanatos
        test = 1*(np.random.rand()<0.05)
        test2 = 1*(np.random.rand()<0.05)
        
        
    P+= 1*(B==1)*(test==1)*(test2==1)
    C+= 1*(test==1)*(test2==1)
    
    
print("Probabilitatea ca o persoana cu 2 teste pozitive sa aiba boala: ",  P/C)

#%% Probabilitatea sa aiba boala cu un test negativ si unul pozitiv sa aiba boala
N=100000

P=0
C=0


for i in range(N):
    
    #alegem o persoana 
    B= 1*(np.random.rand()<0.02)
    
    if B==1:
        #bolnav
        test = 1*(np.random.rand()<0.98)
        test2 = 1*(np.random.rand()<0.98)
    else:
        #sanatos
        test = 1*(np.random.rand()<0.05)
        test2 = 1*(np.random.rand()<0.05)
        
        
    P+= 1*(B==1)*(test + test2 ==1)
    C+= 1*(test + test2 ==1)
    
    
print("Probabilitatea ca o persoana cu 2 teste diferite sa aiba boala: ",  P/C)


#%% Probabilitatea sa aiba boala cu doua teste negative
N=100000

P=0
C=0


for i in range(N):
    
    #alegem o persoana 
    B= 1*(np.random.rand()<0.02)
    
    if B==1:
        #bolnav
        test = 1*(np.random.rand()<0.98)
        test2 = 1*(np.random.rand()<0.98)
    else:
        #sanatos
        test = 1*(np.random.rand()<0.05)
        test2 = 1*(np.random.rand()<0.05)
        
        
    P+= 1*(B==1)*(test==0)*(test2==0)
    C+= 1*(test==0)*(test2==0)
    
    
print("Probabilitatea ca o persoana cu 2 teste negative sa aiba boala: ",  P," / ", C)