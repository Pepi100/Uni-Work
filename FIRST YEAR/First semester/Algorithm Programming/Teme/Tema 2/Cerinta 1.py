""" 1) Scrieți un generator care primeste ca parametrii un număr variabil de liste și o valoare x și furnizează toate listele care conțin valoarea x. """

def generator_liste(*args, x):
    for lista in args:
        if x in lista:
            yield lista


liste = generator_liste([1,2,3,45], [1,567,7564,3,8], [3], [], x= 3)
print( *[x for x in liste], sep= "\n")
