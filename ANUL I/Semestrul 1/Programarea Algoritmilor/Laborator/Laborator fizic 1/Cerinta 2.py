

def modifica_prefix(x, y, prop):
    prefixLength = len(x)
    return " ".join ( [y+cuv[prefixLength:] if cuv[0:prefixLength] == x else cuv for cuv in prop.split() ] )


#print(modifica_prefix("a","minti","am acasa o camila alba"))

def poz_max(lista):
     return tuple ([ int(i + 1) for i in range(len(lista))  if lista[i] == max(lista)])


a, b = tuple(input().split())

f = open("propozitii.in","r")
g = open("propozitii_modificate.out", "a")

str=f.readline()

lista = []
while str:
    strnou = modifica_prefix(a,b,str)
    strnou = strnou + "\n"
    g.write(strnou)
    count = 0
    strnou=strnou.split()
    str = str.split()
    for i in range(len(str)):
        if str[i] != strnou[i]:
            count += 1

    lista.append(count)


    str = f.readline()


print(*poz_max(lista))