import random



def generare_timpi():
    fisier = open("tis.txt", "w")
    numar_persoane = random.randint(5,15)
    valori = [int(x) for x in range (1, 21)]
    valori = random.choices(valori,k = numar_persoane)
    for x in valori:
        fisier.write(str(x)+"\n")
    fisier.close()



def citire():
    fisier = open("tis.txt","r")
    nr_ordine = 0
    lista = []
    str = fisier.read().split()
    for x in str:
        nr_ordine += 1
        lista .append( (nr_ordine, int(x)))

    fisier.close()
    return lista


def afisare_timpi_service(lista):
    timp_asteptare = 0
    suma = 0
    for x in lista:

        print(f"{x[0]:3} {x[1]:3} {timp_asteptare:3}")
        suma += timp_asteptare
        timp_asteptare += x[1]

    print("{:.2f}".format (suma/len(lista)))


def rez_greedy(lista):
    lista.sort(key=lambda x : x[1])
    return lista


generare_timpi()
afisare_timpi_service(citire())
afisare_timpi_service(rez_greedy(citire()))