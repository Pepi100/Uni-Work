# Lab 5 - Generatoare de numere pseudo-aleatoare 

## De ce urmatoarele secvente de cod nu definesc un PRG?



### Candidate 1
```python

seed = int(input("Introduceti seed "))

try:
    while True:
        print(seed)
        seed = seed ^ seed
except KeyboardInterrupt:
    pass
```

La prima iteratie va printa seedul introdus si ulterioar doar valoarea 0

<br>

### Candidate 2

```python

seed = int(input("Introduceti seed "))

try:
    while True:
        print(seed)
        seed = int(seed + seed / 2)
except KeyboardInterrupt:
    pass
```
Valoarea este foarte usor de prezis si se poate observa usor o regula dupa cateva generari.

<br>

### Candidate 3

```python

seed = int(input("Introduceti seed "))

print(seed >> 2)
```

Similar cu candidatul 2, este doar o impartire la 4 care este usor de prezis



## Rezolvati cerintele:

### Genereala o parola de minim 10 caractere care contine cel putin o litera mare, litera mica, o sifra si un caracter special

```python
def isCorrect(password):
    if (
            any(c.islower() for c in password) and
            any(c.isupper() for c in password) and
            any(c.isdigit() for c in password) and
            any(c in '.!$@' for c in password)
    ):
        return True
    return False

password = ''.join(secrets.choice(string.ascii_letters + string.digits + '.!$@') for i in range(10 + secrets.randbelow(10)))
while isCorrect(password) == False:
    password = ''.join(secrets.choice(string.ascii_letters + string.digits + '.!$@') for i in range(10 + secrets.randbelow(10)))

print(password)
    
```
asigura securitatea conturilor
un utilizator isi poate crea o parola sigura pentru un serviciu web



### Genereaza un string URL-safe de 32 de caractere

```python
url = ''.join(secrets.choice(string.ascii_letters + string.digits + '-_') for _ in range(32 + secrets.randbelow(10) ))
print(url)

```
securizeaza accesul la un user session intr-o aplicatie web

### Genereaza un token hexazecimal de cel putin 32 de caractere

```python
print(secrets.token_hex(32 + secrets.randbelow(10)))
```
identificarea unica a tranzactiilor intr-o aplicatie financiara


### Verifica daca doua secvente sunt identice sau nu

```python
secv1 = ''.join(secrets.choice(string.ascii_letters) for i in range(10 + secrets.randbelow(10)))
secv2 = ''.join(secrets.choice(string.ascii_letters) for i in range(10 + secrets.randbelow(10)))

print(secrets.compare_digest(secv1, secv2))
```



### Genereaza o cheie fluida binara care ulterior sa poata fi folosita pentru cryptarea unui mesaj de 100 de caractere

```python

cheie = secrets.token_bytes(100)
text = 'mTpVHVgzVhayFwGanjspjFUNUONVYoCpQdKUEpAzmXBXoAnHSyAZHMreUTqHsJXROOWgSBPeHYXrtnnwbahHssNaHMGOcXBgEzbP'
text_binar = bytes(text, 'ascii')

res = bytes(x ^ y for x, y in zip(cheie, text_binar))
print(res)

```


### Stocheaza parole folosind un modul / o librarie care sa oofere un nivel suficient de securitate

```python

import bcrypt

def hash_and_store_password(password):
    hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
    # stocarea efectiva
    return hashed_password

print(hash_and_store_password("ParolaMiaFrumoasa"))

```


#  folosește un algoritm de hashing lent si include un salt unic pentru fiecare parola