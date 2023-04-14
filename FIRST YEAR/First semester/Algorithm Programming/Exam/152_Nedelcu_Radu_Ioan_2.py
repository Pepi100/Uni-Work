#Nume: Nedelcu Radu-Ioan
#Grupa: 152
#Enunt:[0,5p] Scrieți o funcție citire_matrice care primește un parametru reprezentând numele
#unui fișier care conține elementele unei matrice m x n de numere întregi cu următoarea
#structură:
#- pe prima linie a fișierului sunt m și n
#- pe a doua linie sunt m * n numere separate prin câte un spațiu reprezentând
#elementele matricei transformate în vector prin concatenarea liniilor matricei de la
#prima la ultima; astfel primele n numere sunt elementele primei linii din matrice,
#urmate de elementele celei de a doua linii etc.
#Funcția citește elementele matricei din fișierul cu numele dat ca parametru și returnează
#matricea cu aceste elemente. Dacă în fișierul de intrare nu sunt m x n elemente pe linia a doua
#funcția va returna o listă vidă. Pentru fișierul "matricemn.in" din exemplul de mai jos matricea
#este:
#1 2
#3 4
#5 6
#b) [1,5p] Scrieți o funcție total care primește ca parametri (în această ordine):
#● o matrice (listă de liste)
#● un număr variabil de numere naturale distincte reprezentând indici ai liniilor din
#matrice (indicele primei linii din matrice este 0)
#● un parametru tip care poate primi valoarea 0 sau 1, implicit având valoarea 0.
#Funcția adaugă la finalul matricei, dacă tip = 0, sau la începutul matricei, dacă tip = 1, o linie
#egală cu suma liniilor cu indicii dați ca parametru (suma a două linii se face element cu
#element). Funcția va modifica matricea primită ca parametru.
#c) [1p] Se dă fișierul "matricemn.in" cu structura descrisă la punctul a) (m>2).  Folosind
#apeluri utile ale funcțiilor de la a) și b) să se citească matricea din fișierul “matricemn.in” și să
#se modifice această matrice inserând la începutul matricei o linie cu suma dintre prima și a
#doua linie din matrice și la sfârșitul matricei o linie cu suma dintre penultima si ultima linie din
#matrice. Să se afișeze pe ecran matricea obținută astfel încât elementele de pe fiecare coloană
#să fie aliniate la dreapta, știind că numerele din matrice pot avea maxim 4 cifre.
#


def citire_matrice(fisier):
    f = open(str(fisier), "r")
    mn = f.readline()
    m, n = [int(x) for x in mn.split()]
    valori = f.readline()
    if len([int(x) for x in valori.split()]) is not n*m:
        lista = []
        return lista
    else:
        lista = [int(x) for x in valori.split()]
        matrice = []
        for i in range(m):
            list = []
            matrice.append(list)
            for j in range(n):
                matrice[i].append( int( lista[i*n + j] ) )
        return matrice





def total(matrix, *args, tip = 0):
    lista = [0]* len( matrix[0] )
    for linie in args:
        linie = int(linie)
        for coloana in range( len( matrix[0] ) ):
            lista[coloana] += matrix[linie][coloana]
    if tip is 1:
        matrix.insert(0, lista)
    else:
        matrix.insert(len(matrix), lista )



matrix = citire_matrice("matricemn.in")

total(matrix,0,1,tip=1)
linii = len(matrix)
total(matrix, linii-1, linii-2, tip = 0)

for linie in range(len(matrix)):
    for coloana in range(len(matrix[0])):
        print(str(matrix[linie][coloana]).rjust(4), end= " ")
    print("\n", end="")

