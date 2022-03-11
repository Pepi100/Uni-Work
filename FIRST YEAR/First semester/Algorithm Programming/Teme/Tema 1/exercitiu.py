

f = open("exemplu.txt", "r")
g = open("grupe_cuvinte.txt", "w")

s = f.read()
s = s.lower()

for x in ",.:;!/?`~":
    s = s.replace(x, "")

s = s.split()



grupuri = set()

for x in s:
   grupuri.add("".join( sorted( (set(x)) ) ) )


grupuri = sorted(grupuri, key = len )
grupuri.reverse()

for grup in grupuri:
    listaGrup = set()
    for cuvant in s:
        if grup == "".join( sorted( (set(cuvant)) ) ):
            listaGrup.add(cuvant)
            s.remove(cuvant)

    print(f"Literele {grup}: ",end="", file = g)
    print(*listaGrup, file = g, sep=", ")























