f = open("date.in")



def divizori(n):
    nr_divizori = 0
    for i in range(2,n):
        if n%i == 0:
            nr_divizori += 1
    return nr_divizori






def divEtImp(lista):


    if len(lista) == 1:

        if lista[0] == 1 or lista[0] == 0:
            return 0
        if divizori(lista[0]) ==0:
            return 1
        return 0
    else:
        m = len(lista)//2
        return divEtImp(lista[:m]) + divEtImp(lista[m:])


lista=[]

for linie in f.readlines():
    linie=linie.replace(", "," ")
    linie = linie.replace(",", " ")
    for x in linie.split():
        lista.append(int(x))


print(divEtImp(lista))