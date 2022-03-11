f = open("autori.in", "r")
m, n = tuple(f.readline().split())
m = int(m)
n = int(n)


data={"autori": {}, "carti": {} }

for i in range(m):
    aux = f.readline().split()
    data["autori"][ aux[0] ] = str(aux[1]+ " " + aux[2])
for i in range(n):
    aux = f.readline().split()
    data["carti"][ aux[1] ] = {
        "autor" : aux[0],
        "an" : aux[2],
        "pagini" : aux[3],
        "titlu" : aux[4]
    }

cod = int( input() )

def sterge_carte(data, cod):
    cod = str(cod)
    if cod in data["carti"]:
        aux = data["carti" ][cod]["autor"]

        print("Cartea a fost scrisa de " + data["autori"][aux] )

        data["carti"].pop( cod)
    else:
        print ("Cartea nu exista")





sterge_carte(data, cod)

print(data,sep= "\n")



def carti_autor(data, cod_autor):
    cod_autor = str(cod_autor)
    yield data["autori"][cod_autor]




print(carti_autor(data,"11"))
