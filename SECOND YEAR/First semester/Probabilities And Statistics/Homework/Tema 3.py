# -*- coding: utf-8 -*-
"""
Created on Thu Nov 10 11:28:52 2022

@author: radun
"""
import matplotlib.pyplot as plt
import math
import numpy as np

# Nedelcu Radu - Ioan 252


# Un jucator are m lei pentru un joc. Propuneti un joc pentru un singur jucator astfel incat la fiecare pas al jocului,
# jucatorul poate sa castige o suma de bani sau pierde (eventual alta) suma de bani. 
# Jocul se termina atunci cand jucatorul nu mai are bani (i.e. m=0) sau atinge suma dorita de M lei, M>m. 
# Creati un fisier in Python in care :
# sa simulati jocul propus;
# sa estimati numeric (frecventionist) probabilitatea ca jucatorul sa atinga suma de M lei stiind ca la inceputul jocului a avut m lei;
# sa afisati histograma corespunzatoare lungimii (duratei) jocurilor simulate.

#%% Jocul de barbut
#  Simularea jocului propus
# Jucatorul vine cu cati bani doreste

m = 0;

print("Bine ati venit la jocul de barbut!\nIntroduceti suma cu care doriti sa incepeti: ")
m = int (input())

while m != 0:
    print("Aveti", m , ("lei" if m>1 else "leu" ) )
    print("Introduceti suma pe care doriti sa o paritati sau introduceti 0 pentru a iesi din joc: ")
    
    
    x = int (input())
    if x == 0:
        break;
    if x < 0:
        x= -x
    
    jucator = np.random.randint(1,7);
    adversar = np.random.randint(1,7);
    
    print("Amandoi ati dat cu zarul. Dumneavoastra:" , jucator , "vs" , adversar , "al adversarului");
    
    if jucator == adversar:
        print("Numeni nu a castigat nimic!")
    if jucator > adversar:
        print("Felicitari! Ati castigat", x, ("lei" if x>1 else "leu" ))
        m += x;
    if jucator < adversar:
        print("Ghinion! Ati pierdut", x, ("lei" if x>1 else "leu" ))
        m -= x; 


#%%
# calculam probabilitati

# m = suma de bani de la care plec, x este suma de bani pariata la fiecare runda, x<m, si ideal m multiplu de x
m = 10 
x=1
N = 10000

#recomand x =2 si un N mai mic pentru ca programul sa ruleze mai rapid

# calculam probabilitatea sa ajunga la M, unde M este intre m*2 si m*5
listaM = []
listaProbabilitati = []
for i in np.arange(2.0, 5.5, 0.5):
    M = m*i
    listaM += [M]
    C=0
    for n in range(N):
        #simulam N jocutele si vedem in cate dintre aceastea am ajuns la M
        bani = m
        
        while bani != 0 and bani != M:
            
            jucator = np.random.randint(1,7)
            adversar = np.random.randint(1,7)
            
            if jucator > adversar:
                bani += x
            if jucator < adversar:
                bani -= x
        
        if bani == M:
            C +=1
    
    listaProbabilitati += [C/N]
    print("Probabiliteatea de a ajunge la m*",i," este: ", C/N, sep="")
    
    
plt.plot(listaM,listaProbabilitati , 'C0')
# observam ca probabilitatea aproximativa de a ajunge la M este 1/i, unde i este M/m
# adica probabilitatea de a ajunge la M este m/M

#%% histograma lungimii jocurilor
# pentru un i dat
m = 20 
x=1
N = 1000
i=2

M = m*i

lungimi = []
for n in range(N):
        #simulam N jocutele si vedem in cate dintre aceastea am ajuns la M
    bani = m
    l = 0
    while bani != 0 and bani != M:
        l+=1;
        jucator = np.random.randint(1,7)
        adversar = np.random.randint(1,7)
            
        if jucator > adversar:
            bani += x
        if jucator < adversar:
            bani -= x
        
    lungimi += [l]
    
plt.hist(lungimi)
print("Lungimea medie a unui joc pentru m =",m, "si M =",M," este:", np.average(lungimi))
#pentru M  = 2*m, lungimea medie pare sa fie 1.2 * m*m, cu 20% mai mare decat cea a exercitiului din laborator
# unde s-a observat doar m*m
# banuiesc ca se datoreaza faptului ca in jocul de barbut exista posibilitatea unei egalitati, care prelungeste lungimea jocului
# fara sa afecteze suma de bani


