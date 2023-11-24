# Laboratorul 8 - Tipuri de fisiere, fisiere Portable Executable


## Răspundeți la urmatoarele cerinte referitoare la fisierul [malware.png]()

> Când ați deschis imaginea prin dublu click ce puteți observa? Este ceva suspicios? A 
apărut vreo eroare?

Am observat dificultati in a dezarhiva fisierul

<br>

> Când ați deschis imaginea in HxD ați sesizat ceva suspicios? Daca da, ce? 

<br>

In a doua parte a fisierului gasim si bytes care nu sunt parte din imagine, ci dintr-un set de instructiuni.

<br>

> Încărcați imaginea în [VirusTotal](https://www.virustotal.com/gui/home/upload). Ce rezultate ati obținut? 

Sunt gasite threat-uri de la 2 vendori:

- W32/Agent.ADMH!tr de la Fortinet

- Trojan.Agent!8.B1E de la Rising

<br>

> Folosiți HxD și extrageți conținutul suspicios, apoi încărcați ceea ce ați extras din imagine în VirusTotal. Ce rezultate ați obținut? 

Acum sunt gasite foarte multe tiputi de threat-uri.


> Fișierele din DLLs.zip sunt de folos? Argumentați.

Fisierele DLL sunt librarii care pot fi accesate de mai multe fisiere simultan de mai multe programe. Ele ajuta la eficientizarea memoriei.

<br>


> Este/conține imaginea un malware? Care a fost raționamentul pe care l-ați urmărit

<br>

## Buffer Overflow

### Se da urmatoarea secventa de cod:

```cpp
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char pass[7] = "fmiSSI";
    char input[7];
    int passLen = strlen(pass);
    cout<<"Introduceti parola: ";
    cin>>input;
    if (strncmp(input,pass,passLen)==0){
        cout<<"Parola introdusa este corecta!\n";
    }
    else{
        cout<<"Ati introdus o parola gresita :(\n";
    }
 return 0;

}
```

Orice input de lungime 14 am introduce s-ar evalua ca fiind parola corecta. Un sir de lungima 14 sa suprascrie in totalitate parola initiala, iar strcmp va compara cu passLen = 0.

Aceasta vulnerabilitate se nueste Buffer Overflow

## Detecția fișierelor pe baza valorii hash

> Realizați un script în Python care calculează valoarea SHA256 pentru un fișier de pe 
disk. Realizați un request către VirusTotal folosind [VirusTotal API v3](https://docs.virustotal.com/reference/overview) pentru hash-ul unui 
fișier și afișați numărul de vendori anti-virus care detectează acel fișier, interpretând
răspunsul JSON primit.


## Timestamps

Am atasat [aici]() screenshot-ul din pestudio

Timestamp-ul UNIX este 1700833338 si se gaseste [aici]().
