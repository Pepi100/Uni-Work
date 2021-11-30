

"""Litere, semne"""

propozitie = input()

litereMari, litereMici, semne = 0, 0, 0



for x in propozitie:
    if x != " ":
        if x.isalpha():
            if x.isupper():
                litereMari += 1
            else:
                litereMici += 1
        else:
            semne += 1

print(f"Litere mari: {litereMari}\nLitere mici: {litereMici}\nSemne: {semne}")

















