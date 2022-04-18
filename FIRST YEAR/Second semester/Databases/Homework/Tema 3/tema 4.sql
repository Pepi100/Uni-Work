-- Sa se afiseze lista angajatilor firmei în ordine descresc?toare dup? vechimea în
-- restaurant, împreuna cu job-ul ocupat, anul ?i luna angaj?rii.
SELECT e.last_name as "Nume", j.job_name as "Job",  TO_CHAR(e.hire_date, 'YYYY') as "An", TO_CHAR(e.hire_date, 'MONTH') as "Luna"
FROM restaurant_employees e
JOIN restaurant_jobs j ON j.job_id = e.job_id
ORDER BY e.hire_date ;



-- 2. Sa se afiseze pentru fiecare tara num?rul de angaja?i (pentru ??rile din care nu sunt
-- angaja?i se va afi?a textul 'nu sunt angaja?i').



--Stiu ca am aceeasi bucata de cod pusa de 2 ori dar nu am stiut cum sa fac o 'variabila' pentru ea

SELECT c.country_name as "Tara" , 
   DECODE ( (SELECT COUNT(*)
    FROM restaurant_employees e
    JOIN location_employees l ON e.location_id = l.location_id
    GROUP BY l.country_id
    HAVING l.country_id = c.country_id), NULL, 'Nu sunt angajati', 
    (SELECT COUNT(*)
    FROM restaurant_employees e
    JOIN location_employees l ON e.location_id = l.location_id
    GROUP BY l.country_id
    HAVING l.country_id = c.country_id ) ) as "Numar angajati"
FROM countries_employees c;



-- codul mai curat dar fara inlocuirea lui null:

--SELECT c.country_name as "Tara" , 
--    (SELECT COUNT(*)
--    FROM restaurant_employees e
--    JOIN location_employees l ON e.location_id = l.location_id
--    GROUP BY l.country_id
--    HAVING l.country_id = c.country_id) as "Numar angajati"
--FROM countries_employees c;


-- 3. Sa se afi?eze toate departamentele (doar numele ?i media salariilor) care au
-- valoarea media a salariilor mai mare decat valoarea medie a salariilor la nivelul
-- întregului restaurant.


SELECT  d.department_name as "Nume dep", ROUND(AVG(e.salary),2) as "Salariu mediu"
FROM restaurant_employees e
JOIN restaurant_jobs j ON j.job_id = e.job_id
JOIN restaurant_departments d ON d.department_id = j.department_id
GROUP BY d.department_name
HAVING AVG(e.salary) > (SELECT AVG(m.salary)
                        FROM restaurant_employees m);



--4. Pentru fiecare meniu sa se afiseze nivelul de popularitate (FOARTE POPULAR -
--daca numarul de alegeri reprezinta cel putin o treime din numarul total de meniuri
--alese, POPULAR - daca numarul de alegeri reprezinta cel putin o cincime din
--num?rul total de meniuri alese, iar altfel NU ESTE POPULAR) 

--nr total  de alegeri
--SELECT COUNT(*)
--FROM order_menu om;


SELECT (SELECT m.menu_name
        FROM menus m
        WHERE m.menu_id = o.menu_id) as "Nume", 
        
        CASE
        WHEN COUNT(o.menu_id) >= (SELECT COUNT(*) FROM order_menu)/3 THEN 'FOARTE POPULAR'
        WHEN COUNT(o.menu_id) >= (SELECT COUNT(*) FROM order_menu)/5 THEN 'POPULAR'
        ELSE 'NU ESTE POPULAR'
        END as "Popularitate"
FROM order_menu o
GROUP BY o.menu_id;







