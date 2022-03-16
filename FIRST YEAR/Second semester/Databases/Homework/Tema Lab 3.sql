--22. Scrie?i o cerere pentru a afi?a numele, numele departamentului ?i salariul angaja?ilor 
--care nu câ?tig? comision, dar al c?ror ?ef direct câ?tig? comision.

SELECT e.last_name as "Nume", d.department_name as "Nume departament", e.salary as "Salariu"
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN employees m ON e.manager_id = m.EMPLOYEE_ID
WHERE e.commission_pct IS NULL AND m.commission_pct IS NOT NULL;


--23. S? se afi?eze numele, departamentul, salariul ?i job-ul tuturor angaja?ilor al c?ror 
--salariu ?i comision coincid cu salariul ?i comisionul unui angajat din Oxford.

SELECT e.last_name as "Nume", d.department_name as "Nume departament", e.salary as "Salariu", j.job_title as "Nume job"
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN jobs j ON e.job_id = j.job_id
WHERE (e.salary, e.commission_pct) IN ( SELECT e1.salary, e1.commission_pct FROM employees e1 JOIN departments d1 ON e1.department_id = d1.department_id JOIN locations l ON l.location_id = d1.location_id WHERE LOWER(l.city) = 'oxford' );



--24. S? se afi?eze numele angaja?ilor, codul departamentului ?i codul job-ului salaria?ilor 
--al c?ror departament se afl? în Toronto

SELECT e.last_name as "Nume", e.department_id as "ID Departament", e.job_id as "ID Job"
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN locations l ON l.location_id = d.location_id
WHERE LOWER(l.city) = 'toronto';