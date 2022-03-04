"""
2) Se citește o listă de numere naturale sortată strict crescător și un număr natural S. Să
se afișeze toate perechile distincte formate din valori distincte din lista dată cu
proprietatea că suma lor este egală cu S.
Exemplu: Pentru lista L = [2, 5, 7, 8, 10, 12, 15, 17, 25] și S = 20, trebuie afișate
perechile (5, 15) și (8, 12).
Rezolvati pentru cazul in care numerele nu sunt neaparat distincte!! Trebuie sa calculati cate perechi sunt


"""

lista = [ int(x) for x in input("Citire lista: ").split()]
suma =  int(input("Citire suma: "))
perechi = 0



dictionar = {lista[0]:1}



for i in range(1,len(lista)):
    if(lista[i] != lista[i-1]):
        dictionar[lista[i]] = 1
    else:
        dictionar[lista[i]] += 1


for valoare in dictionar:
    if valoare > suma:
        break
    if valoare * 2 == suma:
        perechi += (dictionar[valoare] - 1) * dictionar[valoare] //2

    elif (suma - valoare) in dictionar:
        perechi +=  ( dictionar[valoare] * dictionar[suma - valoare] )
    dictionar[valoare] = 0



print(f"Numarul de perechi este: {perechi}")