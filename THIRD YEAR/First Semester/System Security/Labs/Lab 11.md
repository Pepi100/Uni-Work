# Laboratorul 11 - Semnături și certificate digitale


## 1. Noțiuni introductive 

Următoarele întrebări se referă la certificatul digital al site-ului facultății:

Cine a emis certificatul digital? 

> Certificatul a fost emis de **Let's Encrypt**

Care este validitatea certificatului? 

> Certificatul este valid pana la data de **23 martie 2024**

Pe câți biți este definită cheia publică? 
> 2048

Care este valoarea exponenților de criptare din  certificat  și  din  certificatele  care îl atestă în lanț? Ce observați? Are aceasta impact asupra securității

<br>

## 2. Generarea cheilor folosind Putty

Descărcați puttygen.exe.

Generați o pereche de chei cheie publică - cheie privată RSA pe 2048 de biți. Apăsați Generate. 


<img src = "https://github.com/Pepi100/Uni-Work/blob/master/THIRD%20YEAR/First%20Semester/System%20Security/Labs/Keygen.png" width = "400px">

Adaugati PassPhrase. La ce folosește aceasta? 

> PassPhrase-ul este folosit pentru a cripta cheia publica pe disc.

Exportați  cheia  publică în  fișierul  public_key.pub, cheia secretă în  fișierul private_key.ppk. Pentru aceasta, folositi Save public key, respectiv Save private key. 

Exportați  cheia  în  format  openssh.  Pentru  aceasta,  accesați  Conversions  și  Export OpenSSH key. 

Deschideți și vedeți ce conțin toate fișierele generate. 
   
