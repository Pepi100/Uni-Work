SELECT EMPLOYEE_ID as "emp emp", FIRST_NAME FROM EMPLOYEES;

DESC employees;

--5
SELECT e.employee_id, e.first_name, e.job_id, e.hire_date
FROM employees e;

--6
SELECT e.employee_id cod, e.first_name nume, e.job_id job, e.hire_date "data angajarii"
FROM employees e;

--7
--cu duplicate
SELECT e.job_id
FROM employees e;

--fara duplicate
SELECT DISTINCT e.job_id
FROM employees e;

--8
SELECT e.first_name || ', ' || e.job_id "ANGAJAT SI TITLU"
FROM employees e;

--10
SELECT e.first_name, e.salary
FROM employees e
WHERE e.salary > 2850;

--11
SELECT e.first_name, e.department_id
FROM employees e
WHERE e.employee_id = 104;

--12
SELECT e.first_name, e.salary
FROM employees e
WHERE e.salary < 1500 OR e.salary > 2850;

SELECT e.first_name, e.salary
FROM employees e
WHERE e.salary NOT BETWEEN 1500 AND 2850;

SELECT e.first_name, e.salary
FROM employees e
WHERE NOT(e.salary >= 1500 AND e.salary <= 2850);

--13
SELECT first_name, job_id, hire_date
FROM employees
WHERE hire_date BETWEEN '20-FEB-1987' AND '1-MAY-1989' 
ORDER BY hire_date;

--14
SELECT e.first_name nume, e.DEPARTMENT_ID
FROM employees e
WHERE e.department_id IN (10, 30, 50)
ORDER BY nume;

--15
SELECT e.first_name as angajat, e.salary as "salariu lunar"
FROM employees e
WHERE e.salary > 1500 AND e.department_id IN (10, 30, 50);

--16
SELECT TO_CHAR(SYSDATE, 'DD-MON')
FROM dual;

--17
SELECT first_name, hire_date
FROM employees
WHERE hire_date LIKE ('%87%');

SELECT first_name, hire_date
FROM employees
WHERE TO_CHAR(hire_date, 'YYYY')='1987';

SELECT first_name, hire_date
FROM employees
WHERE EXTRACT(YEAR from hire_date)=1987;

--18
SELECT e.first_name, e.last_name, e.hire_date
FROM employees e
WHERE TO_CHAR(e.hire_date, 'DD') = (SELECT TO_CHAR(SYSDATE, 'DD') FROM dual);

SELECT e.first_name, e.last_name, e.hire_date
FROM employees e
WHERE TO_CHAR(e.hire_date, 'DD') = TO_CHAR(SYSDATE, 'DD');

--19
SELECT e.first_name, e.job_id
FROM employees e
WHERE e.manager_id IS NULL;

--20
SELECT e.first_name, e.salary, e.commission_pct
FROM employees e
WHERE e.commission_pct IS NOT NULL
ORDER BY e.salary DESC, e.commission_pct DESC;

--21
SELECT e.first_name, e.salary, e.commission_pct
FROM employees e
ORDER BY e.salary DESC, e.commission_pct DESC;
-- INREG CU NULL SUNT DUPA CELE CU VALOARE (ASC)
-- INREG CU NULL SUNT INAINTEA CELOR CU VALOARE (DESC)

--22
SELECT e.first_name
FROM employees e
WHERE e.first_name LIKE '__a%';

--23
SELECT e.first_name
FROM employees e
WHERE LOWER(e.first_name) LIKE '%l%l%' AND (e.department_id = 30 OR e.manager_id = 102);

--24
SELECT e.first_name, e.job_id, e.salary
FROM employees e
WHERE (e.job_id LIKE '%CLERK%' OR e.job_id LIKE '%REP%') AND e.salary NOT IN (1000, 2000, 3000);

--25
SELECT d.department_id
FROM departments d
WHERE d.manager_id IS NULL;