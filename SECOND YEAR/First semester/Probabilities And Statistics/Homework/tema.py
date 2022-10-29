
import matplotlib.pyplot as plt
import math
import numpy as np

N = 20000
intersectii = 0;

length=0.5
linii = 2
floor =[]

intersectii = 0

plansa = plt.subplot()
#ac

for j in range(linii):
        floor.append(j)
        plansa.hlines(y=floor[j], xmin=0, xmax=1, color='black', linestyle='--', linewidth=2.0)


for i in range(N):
    #generam N ace
    x = np.random.uniform(0, 1)
    y = np.random.uniform(0, 1)
    theta = math.radians(np.random.uniform(0,180))
    
    #calculam capetele acului
    capete = np.array([np.add([x,y], -1*np.array([length/2 * math.cos(theta), length/2*math.sin(theta)])), np.add([x,y], [length/2 * math.cos(theta), length/2*math.sin(theta)])])
    
    plansa.plot([capete[0][0], capete[1][0]], [capete[0][1], capete[1][1]], color='blue', linewidth=0.5)

    
    
    for j in range(linii):
        #daca y dintr-un capat este sub linie, iar celalalt capat peste, atunci acul trece peste linie
        if capete[0][1] < floor[j] and capete[1][1] > floor[j] or capete[0][1] > floor[j] and capete[1][1] < floor[j]:
            intersectii +=1;
            
            


print(N / intersectii);

 

