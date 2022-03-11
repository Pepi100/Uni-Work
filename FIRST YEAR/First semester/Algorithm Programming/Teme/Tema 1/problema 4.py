
"""Cifrul lui Cezar"""

"Functii:"
def decifrare(sir, valoare):
    if valoare > 0:
        valoare = -valoare

    cifrare(sir, valoare)

def cifrare(sir, valoare):
    s2 = ""
    for i in range(len(sir)):
        if sir[i].isalpha():
            if sir[i].islower():
                s2 += chr( ord('a') + ( ord(sir[i]) + valoare - ord('a') ) % 26  )
            else:
                s2 += chr(ord('A') + (ord(sir[i]) + valoare - ord('A')) % 26)
        else :
            s2 += sir[i]

    print(s2)



"Program:"

modalitate = int(input( " Cifrare (1) sau decifrare (0) ? :" ))


sir = input("Sirul initial: ")

valoare_deplasare = int(input("Valoare: "))

if modalitate == 1:
    cifrare(sir, valoare_deplasare)
else:
    decifrare(sir, valoare_deplasare)

















