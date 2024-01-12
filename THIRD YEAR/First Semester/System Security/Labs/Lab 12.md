# Laboratorul 12 - Practici de securizare a codului



## Marcați cu Adevărat (A) sau Fals (F) afirmațiile de mai jos.  

Ca să analizați/testați securitatea aplicației, ajută să gândiți ca un atacator. 

> Adevarat

Pentru  că  sunt  foarte  multe,  din  punct  de  vedere al logicii/design-ului aplicației, nu încercați  să  acoperiți  toate  cazurile  posibile  pentru  a  preveni un comportament neașteptat. 

> Fals

Întotdeauna validați câmpurile de input,  atât ca format (tip de date, protejare împotriva SQL injection, etc.) dar și ca valori (dimensiuni, valori minime/maxime, verificări între diferite câmpuri de input;  ex. data de început a unei activități anterioară datei  de  final, prețurile să aibă valori pozitive, etc.)

>Adevarat

Aveți în vedere vulnerabilități de tip buffer overflow. 

> Adevarat

În general nu e o practică bună să stocați log-uri, pentru că ocupă spațiu și cresc timpul de așteptare al utilizatorului. 

> Fals, log-urile ne pot ajuta sa identificam anumite probleme la rularea aplicatiei. Mai mult, acestea ne pot ajuta sa identificam atacuri in timp real. 

Oferiți  cât  mai  multe  detalii  posibile  utilizatorilor  când  eșuează autentificarea  prin username  și parolă sau când implementați mecanisme de recuperare a parolei, pentru a facilita accesul acestora (spre exemplu menționați „Adresa de e-mail nu corespunde unui cont activ” la încercarea de a recupera parola prin e-mail).

> Fals, nu este o idee buna sa oferim cat mai multe detalii utilizatorilor deoarece aceste detalii pot fi folosite si de atacatori pentru a afla mai multe despre utilizatorii din baza de date.

Nu rețineți parole în clar. 

> Adevarat, parolele retinute sau transmise in clar vor pune in pericol toti utilizatorii lor daca un atacator reuseste sa faca rost de fisierele in care aceastea se afla.

Hardcodați parole în cod.

> Fals, hardcodarea parolelor in cod are aceleasi efecte negative ca si retinerea acestora in clar. Mai mult, persoanele care trebuie sa aiba acces la cod, respectiv persoanele care trebuie sa aiba acces la parole se pot schimba ulterior. 

> Mai mult, anumite sectiuni de cod pot fi refolosite in alte parti ale programmului sau codul poate deveni open-source.

<br>

## Buffer Overflow

