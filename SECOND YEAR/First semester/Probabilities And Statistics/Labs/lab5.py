
import matplotlib.pyplot as plt
import math
import numpy as np

#%% EX1
N = 20000
A= 0 #z1 =3
B= 0#z2 =4
C= 0#z1 + z2 =7

AC =0
AB =0
BC =0
ABC = 0


for i in range(N):
    z1 = np.random.randint(1,7);
    z2 = np.random.randint(1,7);
    
    # calculam probabilitatea pentru fiecare dintre evenimente

    if z1 == 3:
        A+=1
        
    if z2 == 4:
        B+=1
        
    if z1 + z2 == 7:
        C+=1;
        
    #calculam probabilitatea ca ele sa se intample simultan
    
    if z1 == 3 and z2 == 4:
        AB+=1;
        AC+=1;
        BC+=1;
        ABC+=1;
    
   
        
        
        
        
print("Probabilitatea lui A: ", A/N);
print("Probabilitatea lui B: ", B/N);
print("Probabilitatea lui C: ", C/N);


print("Probabilitatea lui A ∩ B: ", AB/N, ", iar P(A) * P(B): ", A/N*B/N); #aprozimativ egale
print("Probabilitatea lui A ∩ C: ", AC/N, ", iar P(A) * P(C): ", A/N*C/N); #aprozimativ egale
print("Probabilitatea lui B ∩ C: ", BC/N, ", iar P(B) * PCB): ", C/N*B/N); #aprozimativ egale
print("Probabilitatea lui A ∩ B ∩ C: ", ABC/N, ", iar P(A) * P(B) * P(C): ", A/N*B/N*C/N); #diferite

#%% 2

N = 20000
A= 0 #z1 <= 2
B= 0 #z1 + z2 =7
C= 0 #z2 par

AC =0
AB =0
BC =0
ABC = 0


for i in range(N):
    
    z1 = np.random.randint(1,7);
    z2 = np.random.randint(1,7);
    
    # calculam probabilitatea pentru fiecare dintre evenimente

    if z1 <= 2:
        A+=1
        
    if z2 + z1 == 7:
        B+=1
        
    if z2 % 2 == 0 :
        C+=1;
        
    #calculam probabilitatea ca ele sa se intample simultan
    
    if z1 <= 2 and z2 + z1 == 7 :
        AB+=1;
        
        
    if z1 <= 2 and z2 % 2 == 0 :   
        AC+=1;
        
    if z2 % 2 == 0 and z2 + z1 == 7 :
        BC+=1;
        
    if z2 % 2 == 0 and z2 + z1 == 7 and z1 <= 2:    
        ABC+=1;
    
   
        
        
print("Probabilitatea lui A: ", A/N);
print("Probabilitatea lui B: ", B/N);
print("Probabilitatea lui C: ", C/N);


print("Probabilitatea lui A ∩ B: ", AB/N, ", iar P(A) * P(B): ", A/N*B/N); #aprozimativ egale
print("Probabilitatea lui A ∩ C: ", AC/N, ", iar P(A) * P(C): ", A/N*C/N); #aprozimativ egale
print("Probabilitatea lui B ∩ C: ", BC/N, ", iar P(B) * PCB): ", C/N*B/N); #aprozimativ egale
print("Probabilitatea lui A ∩ B ∩ C: ", ABC/N, ", iar P(A) * P(B) * P(C): ", A/N*B/N*C/N); #aproximativ egale


#%%

N = 200000

a= -0.5
b = 0.5
c= -0.2
d = 0.7


A =0 # x apartine [a,b]
B =0 # y apartine [c,d]
AB = 0
AB2 = 0

for i in range(N):
    
    x= np.random.uniform()*2 -1
    y= np.random.uniform()*2 -1
    
    
    # calculam probabilitatea pentru fiecare dintre evenimente

    if x <= b and x >= a:
        A+=1
        
    if y <= d and y >= c:
        B+=1
   
        
    #calculam probabilitatea ca ele sa se intample simultan
    
    if y <= d and y >= c and x <= b and x >= a:
        AB+=1;
        
    if -x <= d and -x >= c and x <= b and x >= a:
        AB2+=1;
        
    
print("Probabilitatea lui A: ", A/N);
print("Probabilitatea lui B: ", B/N);

print("Probabilitatea lui A ∩ B: ", AB/N, ", iar P(A) * P(B): ", A/N*B/N); #aprozimativ egale
print("Probabilitatea lui A ∩ B atunci cand y = -x: ", AB2/N, ", iar P(A) * P(B): ", A/N*B/N); #diferite

#%% Ex 4

N = 2000
m = 30
M = 2*m

lengths = []
for i in range (N):
    #simulam N jocuri
    
    bani = m;
    
    length = 0;
    while bani !=0 and bani != M:
        length +=1;
        moneda = np.random.uniform(0,1);
        if moneda < 0.5:
            bani-=1
        else:
            bani +=1
    
    lengths += [length];
    

plt.hist(lengths)
plt.show()

print(np.average(lengths))
            
#%% Ex 4 extra

#vedem cum se midifca lungimea average in functie de m
N = 2000

muri = []
averageuri = []
for m in range(5, 26, 5):
    M = 2*m
    lengths = []
    muri += [m]
    for i in range (N):
        #simulam N jocuri
        
        bani = m;
        
        length = 0;
        while bani !=0 and bani != M:
            length +=1;
            moneda = np.random.uniform(0,1);
            if moneda < 0.5:
                bani-=1
            else:
                bani +=1
        
        lengths += [length];
        

    # plt.hist(lengths)
    
    averageuri += [np.average(lengths)];

plt.plot(muri,averageuri , 'C0')
#observam ca lungimea medie a jocului este m*m, atunci cand M este 2*m

    