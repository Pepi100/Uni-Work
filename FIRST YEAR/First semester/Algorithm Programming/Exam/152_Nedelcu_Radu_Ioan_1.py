#Nume: Nedelcu Radu-Ioan
#Grupa: 152
#Enunt: Fișierul text text.in conține, pe mai multe linii, un text în care cuvintele sunt despărțite
#prin spații și semnele de punctuație uzuale. Să se scrie în fișierul text text.out literele din textul
#dat care au frecvențele relative nenule, precum și frecvențele lor relative, conform modelului
#din exemplul de mai jos. Frecvența relativă a unei litere într-un text este egală cu raportul
#dintre frecvența sa în textul respectiv și numărul total de litere din acel text. Literele vor fi
#scrise în fișierul text.out în ordinea descrescătoare a frecvențelor lor, iar în cazul unor
#frecvențe egale vor fi ordonate alfabetic. Nu se va face distincție între litere mici și litere mari.

f = open("text.in", "r")
str= f.read()
str = str.lower()
punctuatie = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''

for char in str:
    if char in punctuatie:
        str= str.replace(char, "")
    if char is '\n':
        str=str.replace('\n', " ")

str= str.replace(" ", "")

nr_litere = int(  len(str) )

litere = {}

for char in str:
    if char in litere:
        litere[char] += 1
    else:
        litere[char] = 1

for a in litere:
    litere[a] = round( litere[a]/nr_litere, 3)

f.close()
f = open("text.out", "w")

for a in sorted(litere.keys(), key=lambda x: (-litere[x],x)):
    f.write(f"{a}: {litere[a]:.3f}\n")



f.close()




print(litere)