# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

#%%
import numpy as np
#chestii pe care un API le ia si le implementeaza in C

import matplotlib.pyplot as plt

#%%

O = np.zeros((2,3))
F = np.full((2,3),7)

G = np.random.normal(0.1,(2,7))

A = np.arange(0,1,0.01)
print(A)


new_m = np.array([[1,2,3],[4,5,6],[7,8,9]])
                  
b = new_m[0:2,0:2]
# de copiaza doar pointerul

b = np.copy(new_m[0:2,0:2])
# o noua copie

#%%

print(np.ravel(new_m))

#%%
a1 = np.array([[1,2],[3,4]])

a2 = np.array([[3,4],[5,6]])

print(a1^a2)

#%%

x=np.array([[1,2,3],[3,4,5]])
# shape (2,3)
print (np.sum(x,1))
print(np.mean(x,0))
#%%

# operatie de broadcasting
O= np.ones((3,3))
x=np.array([3,3,3])

print (0+x)

# reguli de broadcasting:
#daca lungimile shapeurileor nu sunt egale, completez cu 1
# compatibilitate pe axe:
# pe aceeasi axa am numere egale sau cand unul dintre ele este unu

x= np.arange(0, 3*np.pi, 0.1)
y=np.sin(x)
z=np.cos(x)
plt.plot(x,y,'+')
plt.plot(x,z,'*')
plt.xlabel("Axa x")
plt.title("Graficul functiilor sinus si consinus")

plt.show()

# Tema
# images.zip -> car_<x>.npy
# in numpy puten salva array-uri, save(<nume>, <path>), si poate ulterior fi citit
# mp.load(<path>)
# #m- np.zeroes(9,400,600)
# apoi np.sum
# np.max
# np.argmax
# calculati media -> inaginea medie
# biblioteci imagini:
# OpenCV
# PIL

# 
# normalizat imagine =  (x - medie ) / deviatia standard




                  