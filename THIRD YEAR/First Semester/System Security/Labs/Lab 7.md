# Laboratorul 7 - Notiuni introductive

Hashing with and without [salt](https://en.wikipedia.org/wiki/Salt_(cryptography)).

## Răspundeți cu adevărat sau fals

> 1.  Amestecarea ingredientelor pentru realizarea unei prăjituri poate fi considerată one-way 
function.

Da, poate fi considerată un one-way function deoarece procesul de amestecare a ingredientelor este ireversibil.

<br>

> 2. Funcția hash MD5 este considerată sigură la coliziuni.

Nu, nu este considerata libera de coliziuni deoarece se pot gasi coliziuni in [doar cateva secunde](https://www.okta.com/identity-101/md5/#:~:text=The%20MD5%20hash%20function's%20security,be%20used%20for%20malicious%20purposes.).


<br>

> 3. SHA256 este o funcție hash cu output pe 256 biți. 

Da.

<br>

> 4. Valoarea hash SHA-1 pentru cuvantul „laborator” este 0x4bcc6eab9c4ecb9d12dcb0595e2aa5fbc27231f3.

Urmatoarea secventa de cod produce **4bcc6eab9c4ecb9d12dcb0595e2aa5fbc27231f3** ca si output, deci afirmatia este adefarata.

```python
    import hashlib
    str = "laborator"
    result = hashlib.sha1(str.encode())
    print(result.hexdigest())
```

<br>

> 5.  Este corect să afirmăm că „o funcție hash criptează”

Nu este corect sa afirmam acest lucru deoarece criptarea presupune folosirea unei chei pentru a encoda si decoda informatia.

<br>

> 6.  O funcție hash folosită pentru stocarea parolelor trebuie să fie rapidă (i.e., să se calculeze rapid H(x) pentru x dat).

Nu, o functie de hash nu trebuie sa fie rapida, pentru ca o functie rapida ar permite unui atacator sa incerce mai repede un numar mare de parole. Invers, daca functia de hash este mai lenta, atunci un posibil atacator va avea nevoie de mai multe resurse pentru a desfasura un atac.

<br>

> 7. Hash-ul (fără salt) - 095b2626c9b6bad0eb89019ea6091bd9 – corespunde unei parole sigure, 
care nu ar fi susceptibilă spre exemplu la un atac de tip dicționar.

Nu, folosirea unui hash fara salt este susceptibila la un atac de tip dictionar.

<br>
<br>

## Securitatea funcției hash PHOTON-80/20/16
