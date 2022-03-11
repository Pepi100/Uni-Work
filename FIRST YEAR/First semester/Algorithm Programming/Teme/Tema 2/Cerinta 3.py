"""
3)a) Scrieți o funcție generică care să furnizeze numărul elementelor dintr-o colecție
iterabilă care au o anumită proprietate, implementată sub forma unei funcții cu un
singur parametru care returnează True dacă acesta are proprietatea cerută sau
False în caz contrar.

"""

def numerare_generica(colectie, functie):
  if type(colectie[0]) is list or  type(colectie[0]) is tuple: #adaugat pentru functia numarul 3 (ePereche)
    suma = 0
    for iterabil in colectie:
      suma += len([x for x in iterabil if functie(x,colectie) == True])
    return suma
  else: return len([ x for x in colectie if functie(x) == True])



"""
b) Scrieți câte o funcție care să implementeze proprietatea necesară pentru ca funcția de
numărare să furnizeze:
• numărul valorilor pare dintr-o listă/tuplu de numere întregi;
• numărul vocalelor dintr-un șir de caractere;
• numărul perechilor (x, y) cu proprietatea că x = y dintr-o listă de tupluri;
• numărul șirurilor de lungime k dintr-o listă de șiruri de caractere;
• numărul valorilor x dintr-o listă de numere întregi pentru care cmmdc(x, y) =
t, unde y și t sunt date.


"""
def ePar(x):
  if x%2 == 0:
    return True
  return False

def eVocala(x):
  if x in "aeiouAEIOU":
    return True
  return False


def ePereche(x, colectie):
  count = 0
  for iterabil in colectie:
    count += iterabil.count(x)
  if count >=2:
    return True
  return False


k = 5

def lungimeK(x):
  global k
  if len(x) == k:
    return True
  return False

y = 6
t = 2

def eCmmdc(x):
  global y
  global t
  a = y

  while x != 0:
    r = a % x
    a = x
    x = r
  if a == t:
    return True
  return False


lista = [ (1,2,3,4,5), (999,9999,999999), (3, 4, 999) ]

print(numerare_generica(lista, ePereche))


