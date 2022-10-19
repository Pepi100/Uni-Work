# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import matplotlib.pyplot as plt
import numpy as np

x=np.linspace(-50, 50)#
y=x**3

plt.figure()
plt.plot(x,y)

#%% Paradoxul Bertand I

N=500


n=0
plt.figure()

plt.xlim([-1,1])
plt.ylim([-1,1])
plt.axis('equal')

for i in range(N):
    theta = 2* np.pi* np.random.rand(2)
    x= np.cos(theta)
    y=np.sin(theta)
    
    #VARIANTA 1
    # l=np.sqrt( (x[1]-x[0])**2 + (y[1]-y[0])**2  )
    # if l>np.sqrt(3):
    #     n+=1
        
    #VARIANTA 2
    m=np.array([(x[0]+x[1])/2,(y[0]+y[1])/2 ])
    lm = np.sqrt(m[1]**2+m[0]**2)
    if lm < 1/2:
        n+=1
    
    plt.plot(m[0],m[1],'C2*')
    plt.plot(x,y,'C0', linewidth=0.5)
    plt.plot(x,y,'C1.')
    
P=n/N
print(P)



#%% Paradoxul Bertand II

N=500


n=0
plt.figure()

plt.xlim([-1,1])
plt.ylim([-1,1])
plt.axis('equal')

for i in range(N):
    theta = 2* np.pi* np.random.rand(1)
    r= np.sqrt(np.random.rand())
        
    
    m=np.array([r*np.cos(theta), r*np.sin(theta)])
    lm = np.sqrt(m[1]**2+m[0]**2)
    if lm < 1/2:
        n+=1
    
    
    
    
    # plt.plot(x,y,'C0', linewidth=0.5)
    # plt.plot(x,y,'C1.')
    plt.plot(m[0],m[1],'C2*')
    
P=n/N
print(P)



#%% Paradoxul Bertand III

N=5000


n=0
plt.figure()

plt.xlim([-1,1])
plt.ylim([-1,1])
plt.axis('equal')

for i in range(N):
    theta = 2* np.pi* np.random.rand(1)
    #r= np.sqrt(np.random.rand())
    r=np.random.rand()
    
    m=np.array([r*np.cos(theta), r*np.sin(theta)])
    lm = np.sqrt(m[1]**2+m[0]**2)
    if lm < 1/2:
        n+=1
    
    
    
    
    # plt.plot(x,y,'C0', linewidth=0.5)
    # plt.plot(x,y,'C1.')
    plt.plot(m[0],m[1],'C2*')
    
P=n/N
print(P)
