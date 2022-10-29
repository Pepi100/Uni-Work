import matplotlib.pyplot as plt
import numpy as np
import math



plt.figure()


#%% Exercitiul 1
# estimati numeric probabilitatea ca un numar generat uniform sa fie in [a,b]


a=0.5
b=1

N = 10000
p=0
for i in range(N):
    nr = np.random.uniform();
    if nr >= a and nr <= b:
        p+=1
        
print("Proabilitatea ca numarul sa fie in intervalul [" , a , ", " , b , "] este: " , (p/N)  )


#%% Exercitiul 2
# Determinati o aproximare a lui pi, stiind ca pi = aria cerc/patrat

N = 100000



p=0
for i in range(N):
    #consider ca 0,0 este centrul cercului si al patratului
    x=np.random.uniform();
    y=np.random.uniform();
    
    # pentru a afla daca se afla in cerc calculam distanta de la 0 0 la punctul generat
    dist = math.sqrt( x*x + y*y  )
    if dist <= 1:
        p+=1
    
print("Proabilitatea ca numarul sa fie in intervalul sa fie in cerc este: " , (p/N)*4  )


#%% Exercitiul 3


N = 1000





for R in range(10):
    p=0
    for i in range(N):
        #consider ca 0,0 este centrul cercului si al patratului
        x=np.random.uniform();
        y=np.random.uniform();
        
        # pentru a afla daca se afla in cerc calculam distanta de la 0 0 la punctul generat
        dist = math.sqrt( x*x + y*y  )
        if dist <= 1:
            p+=1
        
    plt.plot(R,(p/N)*4*R*R, "C0." )
        
        # print("Aria unui cerc de raza ", R, " este " , (p/N)*4*R*R  )




#%% 3 b


N = 10000



#repetam procesul pentru d dimensiuni, aria discului de raza 1 pentru fiecare


for d in range(20):
    p=0
    for i in range(N):
        #consider ca 0,0 este centrul cercului si al patratului
        # x vectorul de puncte
        x=[]
        for j in range(d):
            x.append(np.random.uniform());
    
        # pentru a afla daca se afla in cerc calculam distanta de la 0 0 la punctul generat
        dist = np.linalg.norm(x);
        if dist <= 1:
            p+=1
        
    plt.plot(d,(p/N)*(2**d), "C0." )
    print((p/N)*(2**d))
            
        
#%% 4 estimati numerit aria elipsei


N = 100000

a=4
b=5

p=0
for i in range(N):
    #consider ca 0,0 este centrul elipsei si al patratului
    x=np.random.uniform(-a,a);
    y=np.random.uniform(-b,b);
    
    # pentru a afla daca se afla in cerc calculam distanta de la 0 0 la punctul generat
    if (x/a)**2 + (y/b)**2 <= 1:
        p+=1
    
print("Aria elipsei este: " , (p/N)*4*a*b  )






#%% 5 - Cu Eric Morosan

N = 5000
a = 3
b = 2
n = 0
l_square = 5
for i in range(N):
    z = (2 * np.random.rand(2) - 1)
    theta1 =  z[0] * l_square
    theta2 = z[1] * l_square
    x = theta1
    y = theta2
    l1 = (x ** 2 / a **2) + (y ** 2 / b ** 2)
    l2 = np.sqrt((x-2)**2 + (y-2)**2)
    if l1 <= 1 and l2 <= np.sqrt(2):
        plt.plot(x,y,"C0.")
        n += 1
    elif l1 <= 1:
        plt.plot(x,y,"C2.")
    elif l2 <= np.sqrt(2):
        plt.plot(x,y,"C3.")
    else:
        plt.plot(x,y,"C1.")

prob = n/N
aria = prob * l_square ** 2
print(aria)

#%% Ex 6 in clasa
f1 = lambda x, y: x * 2 + y * 4 + 2 * x * y - 1
f2 = lambda x, y: y * 2 + x * 2 * np.cos(x) - 1
f3 = lambda x, y: np.exp(x * 2) + y * 2 - 4 + 2.99 * np.cos(y)

a = 2
b = 1
N = 100000

x = np.random.uniform(-a, a, N)
y = np.random.uniform(-b, b, N)

n = np.sum(1 * (f1(x,y) <= 0))
P = n/N
aria = P * 4 * a * b
print("Aria domeniului este ", aria)