
-- • filtrare la nivel de linii

--
-- • utilizarea a cel puțin 2 funcții pe șiruri de caractere, 2 funcții pe date calendaristice, a funcțiilor NVL și DECODE, a cel puțin unei expresii CASE



-- Sa se obtină clientul care a cumpărat cel mai ieftin produs
-- prodmin = produsul cel mai ieftin din stocul magazinului
WITH prodmin AS    (SELECT p.ID_PRODUS
                    FROM PRODUS p
                    WHERE p.pret = (SELECT MIN(pret)
                                    FROM PRODUS))
SELECT c.NUME, c.PRENUME ,c.EMAIL
FROM client c
JOIN COMANDA com ON c.ID_CLIENT = com.ID_CLIENT
JOIN PRODUS_COMANDAT pc ON pc.ID_COMANDA = com.ID_COMANDA
 WHERE pc.ID_PRODUS IN (SELECT * FROM prodmin);

-- sa se obtina adresa clientului care a cumparat produsele cu valoarea totala maxima

SELECT *
FROM ADRESA a
JOIN client c ON c.ID_ADRESA = a.ID_ADRESA
WHERE c.ID_CLIENT IN (SELECT ID_CLIENT
                      FROM (SELECT c.ID_CLIENT, sum(p.PRET)
                            FROM client c
                                    JOIN COMANDA com ON c.ID_CLIENT = com.ID_CLIENT
                                    JOIN PRODUS_COMANDAT pc ON pc.ID_COMANDA = com.ID_COMANDA
                                    JOIN PRODUS p ON pc.ID_PRODUS = p.ID_PRODUS
                            GROUP BY c.ID_CLIENT
                            ORDER BY sum(p.PRET) DESC)
                      WHERE rownum = 1);


-- sa se afiseze pentru fiecare reducere valida care este pretul redus al produsului

SELECT p2.nume, p.nume,
    CASE
        WHEN (r.DATA_SFARSIT >= SYSDATE AND r.DATA_INCEPUT <= SYSDATE  AND r.TIP = 'suma') THEN p.PRET - r.VALOARE
        WHEN (r.DATA_SFARSIT >= SYSDATE AND r.DATA_INCEPUT <= SYSDATE AND r.TIP = 'procent') THEN p.PRET*(100 - r.VALOARE)/100
        ELSE 'Reducerea nu mai este valabila'
        END
    as "Pret dupa reducere"
FROM REDUCERE r
JOIN PRODUS P on R.ID_REDUCERE = P.ID_REDUCERE
JOIN PRODUCATOR P2 on P.ID_PRODUCATOR = P2.ID_PRODUCATOR;


SELECT SYSDATE
FROM dual;