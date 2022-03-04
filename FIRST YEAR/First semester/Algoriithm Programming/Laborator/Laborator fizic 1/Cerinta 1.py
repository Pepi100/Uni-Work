
import math

def citire_matrice(fisier):
    f = open(fisier,"r")
    matrix = []
    str = f.readline()
    linie = len(str.split())
    while str:
        matrix.append([int(x) for x in str.split()])
        str = f.readline()
        if linie != len(str.split()) and len(str.split()) >= 1 :
            return None


    return matrix


def multimi(matrix, *args):
    set_intersectie = set ()
    set_reuniune = set()
    for i in args:
         set_intersectie=set_intersectie.union(set([x for x in matrix[i] if x < 0] ))
    for i in args:
         set_reuniune=set_reuniune.union(set([x for x in matrix[i] if x > 0 and x % 10 == (x // pow(10, int(math.log10(x)) ) ) ] ))

    return set_intersectie, set_reuniune

matrix = citire_matrice("input.txt")

n = len(matrix) - 1
aux, pozitive = multimi(matrix,n, n-1, n-2)
negative, aux = multimi(matrix,0)
negative2, aux = multimi(matrix,n)
negative = len(negative.intersection(negative2))
print( *pozitive, "\n",negative)