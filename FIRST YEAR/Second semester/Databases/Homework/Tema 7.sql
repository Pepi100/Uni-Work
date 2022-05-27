--S? se ob?in? magazinul care are în stoc cea mai ieftin? tablet? Nexus 7.
WITH pretmin AS    (SELECT MIN(s.pret), s.cod_produs
                    FROM stoc s
                    WHERE s.cod_produs IN ( SELECT p.id_produs 
                                            FROM produs p
                                            WHERE LOWER(p.denumire) LIKE 'nexus 7')
                    GROUP BY s.cod_produs
                    )
SELECT m.denumire as "Denumire", stoc.pret as "Pret"
FROM magazin m
JOIN stoc ON m.id_magazin = stoc.cod_magazin
WHERE (stoc.pret, stoc.cod_produs) IN (SELECT * FROM pretmin);


--2.S? se ob?in? denumirea produsului din stocul magazinului Emag cu cel mai bun raport pre?/user_rating.

WITH stock AS (SELECT 
                     s.cod_produs as "Cod", p.denumire as "Denumire", (s.pret/p.user_rating) as "Raport"
                FROM stoc s
                LEFT JOIN produs p ON p.id_produs = s.cod_produs
                JOIN magazin m ON s.cod_magazin = m.id_magazin
                WHERE LOWER(m.denumire) LIKE 'emag'
--                acest query va afisa produsele de la cel mai slab la cel mai bun, daca la vrem invers il putem scoate pe "DESC"
                ORDER BY s.pret/p.user_rating DESC )
SELECT *
FROM stock s
WHERE rownum = 1;



--3. S? se afi?eze denumirea categoriei ?i denumirea produselor pentru care este cunoscut? firma care asigur? service.

SELECT c.denumire as "Denumire categorie", p.denumire as "Denumire produs" 
FROM produs p
JOIN categorie c ON c.id_categorie = p.cod_categorie
JOIN producator pt ON p.cod_producator = pt.id_producator
WHERE pt.service IS NOT null;
