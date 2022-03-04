#Nume: Nedelcu Radu-Ioan
#Grupa: 152
#Enunt:Se consideră fișierul text catalog.in cu următoarea structură:
#• pe prima linie apare numărul n reprezentând numărul de elevi dintr-o clasă a unui liceu
#• pe următoarele linii avem informații despre cei n elevi, respectiv pentru fiecare elev
#informațiile sunt structurate astfel:
#▪ linie de forma <șir de caractere> <m>, unde șirul de caractere este numele elevului (acesta
#este unic), iar m este un număr natural reprezentând numărul de materii
#▪ urmată de m linii care conțin notele elevului (numere naturale) la m materii, fiecare având
#următoarea structură:
#<nume_materie>,<nota_1>,<nota_2>,...,<nota_k>
#Observație: Orice elev are la fiecare materie cel puțin o notă, iar denumirile materiilor nu conțin
#caracterul ',' (virgula).

def citire(fisier):
    dictionar= {}
    f = open(fisier, "r")
    n = int(f.readline())
    for elev in range(n):
        #citire nume si note
        str = f.readline()
        str = str.split()
        nume = ""
        for i in range( len(str)-1):
            nume = nume + str[i] + " "
        l = len(nume)
        nume = nume[:l-1]
        materii = int( str[-1])
        dictionar[nume]= {}
        for i in range(materii):
            str = f.readline()
            str = str.replace(',', "!")
            str = str.split("!")

            dictionar[nume][str[0]]= [int(x) for x in str[1::]]
    return dictionar



def detalii_elev(dictionar, nume):
    lista = []
    for materie in dictionar[nume]:
        tuplu = tuple()

        medie = sum(  dictionar[nume][materie] ) / len(dictionar[nume][materie])
        if medie < 5:
            medie = 0
        tuplu = tuplu + (materie,medie)

        lista.append(tuplu)


    return lista




nume = input()

dictionar = citire("catalog.in")
print(dictionar)

sortata = sorted( detalii_elev(dictionar, nume))
for materie in sortata:
    print( f"{materie[0]} {materie[1]:.2f}")