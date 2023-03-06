

import matplotlib.pyplot as plt
import numpy as np
from pydataset import data
import math
from scipy.stats import linregress, poisson
#%%
n= 1000;

u = 0
o = 1

A = []
B = []
C = np.random.normal(u, o, size = n)


x = np.linspace(-2,2,100)
y = 1/(math.sqrt(2*math.pi*o))*(-1*math.e**((x-u)**2)/(2*o))


for i in range(n):

    U = np.random.uniform()
    U2 = np.random.uniform()
    A.append(math.sqrt(-2*math.log(U))*math.cos(2*math.pi*U2))
    B.append(math.sqrt(-2 * math.log(U)) * math.sin(2 * math.pi * U2))

plt.hist(A, color=(0, 0, 1, 0.5));
plt.hist(B,color=(0, 1, 0, 0.5));
plt.hist(C,color=(1, 0, 0, 0.5));
plt.plot(x,y)




plt.show()

#%%

N=100

def solve(X):
    return math.sqrt(N) * (np.sum(X) / N - u)

lmb = 0.5
p = 0.5
X = np.random.uniform(0, 100, N)
Y = np.random.exponential(lmb, N)
Z = poisson.rvs(lmb, N)
T = np.random.geometric(p, N)


#%% ex 4

N = 100
p = 0.5
Y = []
poz = 0

for i in range(N):
    r = np.random.uniform()
    if r <= p:
        poz += 1
    else:
        poz -= 1
    Y.append(poz)
plt.figure()
plt.plot(Y)




