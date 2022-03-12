--Scrie?i o cerere care afi?eaz? numele angajatului, codul departamentului în care acesta lucreaz? 
--?i numele colegilor s?i de departament. 
--Se vor eticheta coloanele corespunz?tor. (24 din laborator)
SELECT  e.LAST_NAME as "Nume" , e.department_id as "Id departament", d.last_name as "Nume coleg"
FROM employees d, employees e
WHERE e.department_id = d.department_id AND CONCAT(e.last_name, e.first_name) != CONCAT(d.last_name, d.first_name);


--2. Scrie?i o cerere care s? afi?eze pentru fiecare angajat care are salariul mai mare decât media job-ului s?u 
--(media aritmetic? dintre min_salary ?i max_salary din jobs) 
--id-ul,valoarea salariului ?i procentul cu care trebuie s? i se 
--m?reasc? salariul pentru a fi cât valoarea maxim? a job-ului s?u.

SELECT e.employee_id as "Id" , e.salary as "Salariu", CONCAT(ROUND((j.max_salary-e.salary)/e.salary*100, 2), '%') as "Marire Necesara"
FROM employees e, jobs j
WHERE  j.job_id = e.job_id AND e.salary > (j.max_salary + j.min_salary)/2;

--3. S? se afi?eze (sub forma 'Ini?ialaFirstName LastName' -nefolosind substr) acele persoane angajate 
--în anii 90 ?i care au fost angajate în al treilea sfert al anului respectiv (f?r? a verifica dac? luna este
--iulie, august sau septembrie) + num?rul de apari?ii al fiec?rei vocale în ‘FirstName’ (câte o coloan? pentru fiecare vocal?) 
--(dac? o vocal? lipse?te se va afi?a 0 pe coloana corespondent? acesteia).

SELECT CONCAT( CONCAT ( CHR(ASCII(e.first_name)), ' '), e.last_name) as "Nume", 
    ( LENGTH(e.first_name) - LENGTH(REPLACE( LOWER(e.first_name),'a','')) ) as "AparitiiA",
    ( LENGTH(e.first_name) - LENGTH(REPLACE( LOWER(e.first_name),'e','')) ) as "AparitiiE",
    ( LENGTH(e.first_name) - LENGTH(REPLACE( LOWER(e.first_name),'i','')) ) as "AparitiiI", 
    ( LENGTH(e.first_name) - LENGTH(REPLACE( LOWER(e.first_name),'o','')) ) as "AparitiiO",
    ( LENGTH(e.first_name) - LENGTH(REPLACE( LOWER(e.first_name),'u','')) ) as "AparitiiU"
FROM employees e
WHERE TO_CHAR(e.hire_date, 'YYYY') LIKE '__9_'  AND TO_CHAR(e.hire_date, 'Q') = 3  ;