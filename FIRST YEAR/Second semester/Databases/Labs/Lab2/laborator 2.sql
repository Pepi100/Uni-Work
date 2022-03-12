SELECT TO_NUMBER('12')
FROM DUAL;

SELECT
    TO_NUMBER('123','9999')
FROM DUAL;

SELECT
    TO_NUMBER('$123,00.91','L999G99D99')
FROM DUAL;

--CHAR -> stocare siruri de lungime fixa (daca lungimea sirului este mai mica decat lungimea fixata la declarare se vor adauga caractere blank)
--VARCHAR -> stocare siruri de lungime variabila

SELECT
    LTRIM('./#./asd','./')
FROM DUAL;

SELECT
    LPAD('asd',4,'./')
FROM DUAL;

SELECT
    LENGTH('')
FROM DUAL;

SELECT
    ROUND(1234.578,-3)
FROM DUAL;

SELECT
    ROUND(TO_DATE(TO_CHAR('12-MAR-2022'), 'DD-MON-YYYY'),'YEAR')
FROM DUAL;

--1
SELECT
    e.first_name || ' ' || e.last_name || ' castiga '
FROM EMPLOYEES e;

SELECT
    CONCAT(e.first_name, CONCAT(' ', CONCAT(e.last_name, ' castiga ')))
FROM employees e;

--2
SELECT 
    INITCAP(e.first_name),
    UPPER(e.last_name),
    LENGTH(e.last_name) lg
FROM employees e 
WHERE LOWER(e.last_name) LIKE 'j%' 
        OR LOWER(e.last_name) LIKE 'm%' 
        OR LOWER(e.last_name) LIKE '__a%'
ORDER BY lg DESC;

SELECT 
    INITCAP(e.first_name),
    UPPER(e.last_name),
    LENGTH(e.last_name) lg
FROM employees e
WHERE SUBSTR(LOWER(e.first_name),1,1) = 'm' 
        OR SUBSTR(LOWER(e.first_name),1,1) = 'j'
        OR SUBSTR(LOWER(e.first_name),3,1) = 'a'
ORDER BY lg DESC;

--3
SELECT
    e.employee_id, first_name, department_id
FROM employees e
WHERE TRIM(BOTH ' ' FROM LOWER(e.first_name)) = 'steven';

--4
SELECT
    e.employee_id,
    e.last_name,
    LENGTH(e.last_name),
    INSTR(e.last_name,'a')
FROM employees e
WHERE SUBSTR(LOWER(e.last_name),-1) = 'e';

--5
SELECT E.EMPLOYEE_ID
FROM employees e
WHERE MOD(ROUND(sysdate - e.hire_date), 7) = 0;

SELECT * 
FROM employees 
WHERE MOD(TRUNC(SYSDATE) - TRUNC(hire_date), 7) = 0;

--6
SELECT
    e.employee_id, e.salary, e.last_name,
    TO_CHAR(e.salary * 1.15,'999999D99'),
    ROUND(e.salary * 1.15 / 100, 2)
FROM employees e
WHERE NOT MOD(e.salary,1000) = 0;

--7
SELECT
    e.last_name, RPAD(e.hire_date,20)
FROM employees e;

--8
SELECT
    TO_CHAR(SYSDATE + 30, 'DD-MON-YYYY HH24:MI:SS')
FROM DUAL;

--9
SELECT
    TO_DATE('31-DEC-' || TO_CHAR(SYSDATE,'YYYY'),'DD-MON-YYYY') - SYSDATE 
FROM DUAL;

--10
--a
SELECT
    TO_CHAR(SYSDATE + 0.5, 'DD-MON-YYYY HH24:MI:SS')
FROM DUAL;

--b
SELECT
    TO_CHAR(SYSDATE + 5/24/60, 'DD-MON-YYYY HH24:MI:SS')
FROM DUAL;

--11
SELECT
    CONCAT(e.first_name, e.last_name),
    e.hire_date,
    NEXT_DAY(ADD_MONTHS(e.hire_date, 6),'Monday')
FROM employees e;

--12
SELECT 
    e.last_name,
    ROUND(MONTHS_BETWEEN(SYSDATE, e.hire_date)) nr
FROM employees e
ORDER BY nr;

SELECT
    first_name,
    ROUND(MONTHS_BETWEEN(SYSDATE, hire_date)) as "luni lucrate"
FROM employees
ORDER BY "luni lucrate";

--13
ALTER SESSION SET NLS_TERRITORY = 'Romania';
SELECT
    e.last_name,
    e.hire_date,
    TO_CHAR(e.hire_date,'DY')
FROM employees e
ORDER BY TO_CHAR(e.hire_date,'D');

ALTER SESSION SET NLS_TERRITORY = 'America';
SELECT 
    first_name, hire_date,
    TO_CHAR(hire_date, 'DAY')
FROM employees e
ORDER BY TO_CHAR(hire_date - 1, 'D');

--14
SELECT
    e.first_name, NVL(TO_CHAR(e.commission_pct),'fara comision')
FROM employees e;

--15
SELECT
    e.first_name, e.salary, e.commission_pct
FROM employees e
WHERE e.salary + e.salary * NVL(e.commission_pct,0) > 10000;

--16
SELECT
    e.first_name, e.job_id, e.salary,
    CASE e.job_id
    WHEN 'IT_PROG' THEN 120/100 * e.salary
    WHEN 'SA_REP' THEN 125/100 * e.salary
    WHEN 'SA_MAN' THEN 135/100 * e.salary
    ELSE e.salary
    END
FROM employees e;

SELECT
    job_id,
    salary,
    DECODE(job_id, 'IT_PROG', salary + 20 / 100 * salary,
                    'SA_REP', salary + 25 / 100 * salary,
                    'SA_MAN', salary + 35 / 100 * salary,
                    salary) as "sal neg"
FROM employees;

--17
SELECT
    e.employee_id, d.department_name
FROM EMPLOYEES e
JOIN departments d ON e.department_id = d.department_id; 

SELECT
    employee_id, department_name
FROM EMPLOYEES
JOIN departments USING (department_id);

SELECT
    e.employee_id, d.department_name
FROM EMPLOYEES e, departments d
WHERE e.department_id = d.department_id;

--18
SELECT
    DISTINCT e.job_id,
    j.job_title
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN jobs j ON j.job_id = e.job_id
WHERE d.department_id = 30;

--19
SELECT
    e.last_name,
    d.department_name,
    l.city
FROM employees e
JOIN DEPARTMENTS d ON d.department_id = e.department_id
JOIN locations l ON l.location_id = d.location_id
WHERE e.commission_pct IS NOT NULL;

--20
SELECT
    e.last_name,
    d.department_name
FROM employees e
JOIN DEPARTMENTS d ON d.department_id = e.department_id
WHERE LOWER(e.last_name) LIKE '%a%';

--21
SELECT
    e.last_name,
    d.department_name,
    l.city
FROM employees e
JOIN DEPARTMENTS d ON d.department_id = e.department_id
JOIN locations l ON l.location_id = d.location_id
WHERE LOWER(l.city) = 'oxford';

--22
SELECT
    e.employee_id, e.last_name, e.manager_id, m.last_name
FROM employees e
JOIN employees m ON e.manager_id = M.EMPLOYEE_ID;