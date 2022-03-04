fisier = open("spectacole.txt", "r")
lista = []

for line in fisier.readlines():
     line = line.replace("-", " ")
     line= line.split(" ", maxsplit=2)
     lista.append( line )


lista.sort(key= lambda x : x[1])
ultimul = "00:00"

with open("programare.txt", "w") as output:
    for inceput, final, nume in lista:
        if inceput < ultimul:
            continue
        output.write(f"{inceput}-{final} {nume}")
        ultimul = final