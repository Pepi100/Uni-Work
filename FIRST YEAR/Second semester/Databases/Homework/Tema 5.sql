--1.
--S? se afi?eze un tabel cu numele angaja?ilor, stabilindu-se pentru fiecare angajat
--dac? a fost „promovat”/„penalizat”/„a p?strat nivelul”. Se consider? c? un
--angajat a fost promovat dac? media salariilor pentru ultimul job de?inut anterior
--este mai mic? decât media salarilor pentru jobul de?inut în prezent. (media
--fiec?rui salariu se va calcula ca media aritmetic? dintre min_sal ?i max_sal din
--jobs). Pentru angaja?ii care nu au mai avut un alt job sa se afiseze mesajul ,,nu a
--avut alt job”.


SELECT e.last_name as "Nume", (j.min_salary + j.max_salary)/2 as "Salariu Mediu Actual", (j2.min_salary + j2.max_salary)/2 as "Salariu Mediu Trecut",
CASE
    WHEN (j2.min_salary IS NULL) THEN 'Nu a avut job anterior'
    WHEN ((j.min_salary + j.max_salary)/2 > (j2.min_salary + j2.max_salary)/2) THEN 'Promovat'
    WHEN ((j.min_salary + j.max_salary)/2 = (j2.min_salary + j2.max_salary)/2) THEN 'A pastrat nivelul'
    ELSE 'Penalizat'
END
FROM employees e
JOIN jobs j on j.job_id =  e.job_id
LEFT JOIN job_history jh ON jh.employee_id = e.employee_id
LEFT JOIN jobs j2 ON j2.job_id = jh.job_id
WHERE jh.start_date = ( SELECT MAX(job_history.start_date)
                        FROM job_history
                        WHERE job_history.employee_id = e.employee_id) OR jh.start_date IS NULL; 
                        
 
-- In aceasta parte aleg pentru fiecare dintre intrarile din job_history doar pe cea unde start_date ul este maxim, adica cea mai recenta, pentru fiecare angajat: 
                        
--WHERE jh.start_date = ( SELECT MAX(job_history.start_date)
--                        FROM job_history
--                        WHERE job_history.employee_id = e.employee_id) OR jh.start_date IS NULL; 
--

--2.
--Managerul companiei are nevoie de urm?toarele informa?ii: numele,
--prenumele, num?rul de subordona?ii direc?i ai celor care lucreaz? în acela?i ora?
--cu el. Este interesat doar de acei angaja?i care au în subordine direct? cel pu?in
--3 angaja?i.


-- Presupun ca managerul companiei este cel cu cea mai inalta functie, job_id: AD_PRES, sub numele de Steven King

--L-am inclus si pe el printre cei care lucreaza in acelasi oras cu el.

WITH oras AS (  SELECT LOWER(l.city)
                FROM employees e
                JOIN departments d on e.department_id = d.department_id
                JOIN locations l ON d.location_id = l.location_id
                WHERE LOWER(e.job_id) = 'ad_pres')
SELECT e.last_name as "Nume", e.first_name as "Prenume",   (SELECT COUNT(employee_id)
                                                            FROM employees
                                                            WHERE manager_id = e.employee_id
                                                            GROUP BY manager_id) as "Subordonati"
FROM employees e
JOIN departments d on e.department_id = d.department_id
JOIN locations l ON d.location_id = l.location_id
WHERE LOWER(l.city) IN (SELECT * FROM oras) AND NOT EXISTS (SELECT COUNT(employee_id)
                                                            FROM employees
                                                            WHERE manager_id = e.employee_id
                                                            GROUP BY manager_id);