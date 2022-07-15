--EX DIVISION
--METODA1
SELECT DISTINCT employee_id
FROM works_on a
WHERE NOT EXISTS
    (
        SELECT 1
        FROM projects p
        WHERE budget=10000 
            AND NOT EXISTS
                (
                    SELECT 'x'
                    FROM works_on b
                    WHERE p.project_id=b.project_id AND b.employee_id=a.employee_id
                )
    );

--METODA2
SELECT employee_id
FROM works_on
WHERE project_id IN
    (
        SELECT project_id
        FROM projects
        WHERE budget=10000
    )
GROUP BY employee_id
HAVING COUNT(project_id)=
    (
        SELECT COUNT(*)
        FROM projects
        WHERE budget=10000
    );

--METODA3
SELECT employee_id 
FROM works_on
MINUS
SELECT employee_id 
FROM
    (
        SELECT employee_id, project_id
        FROM 
            (
                SELECT DISTINCT employee_id 
                FROM works_on
            ) t1,
                (SELECT project_id FROM projects WHERE budget=10000) t2
        MINUS
        SELECT employee_id, project_id 
        FROM works_on
    ) t3;

--METODA4
SELECT DISTINCT employee_id
FROM works_on a
WHERE NOT EXISTS 
(
    (
        SELECT project_id
        FROM projects p
        WHERE budget=10000
    )
     MINUS
    (
        SELECT p.project_id
        FROM projects p, works_on b
        WHERE p.project_id=b.project_id
            AND b.employee_id=a.employee_id
    )
);

--1
--METODA1
SELECT DISTINCT w.employee_id, e.last_name, e.first_name
FROM works_on w
JOIN employees e ON e.employee_id = w.employee_id
WHERE NOT EXISTS(SELECT p.start_date
       FROM projects p
       WHERE p.start_date BETWEEN TO_DATE('2006/01/01', 'yyyy/mm/dd') AND TO_DATE('2006/06/30', 'yyyy/mm/dd')
       AND NOT EXISTS(SELECT w1.employee_id
                     FROM works_on w1
                     WHERE w1.employee_id = w.employee_id
                     AND w1.project_id = p.project_id));

--METODA2
SELECT
    w.employee_id
FROM works_on w
JOIN projects p ON p.project_id = w.project_id
WHERE
    p.project_id IN 
        (
           SELECT
                p.project_id
            FROM projects p
            WHERE p.start_date BETWEEN TO_DATE('01-01-2006','DD-MM-YYYY') AND
                TO_DATE('30-06-2006','DD-MM-YYYY') 
        )
GROUP BY w.employee_id
HAVING COUNT(p.project_id) = 
    (
            SELECT
                COUNT(p.project_id)
            FROM projects p
            WHERE p.start_date BETWEEN TO_DATE('01-01-2006','DD-MM-YYYY') AND
                TO_DATE('30-06-2006','DD-MM-YYYY') 
    );

--METODA3
SELECT DISTINCT employee_id 
FROM works_on 
MINUS 
SELECT employee_id 
FROM
    ( 
        SELECT employee_id, project_id 
        FROM 
            (SELECT employee_id FROM works_on) t1, 
            (SELECT project_id FROM projects WHERE start_date BETWEEN TO_DATE('2006/01/01', 'yyyy/mm/dd') AND TO_DATE('2006/06/30', 'yyyy/mm/dd')) t2 
        MINUS 
        SELECT employee_id, project_id FROM works_on 
    ) t3; 

--METODA4
SELECT DISTINCT w.employee_id, e.first_name, e.last_name
FROM works_on w
JOIN employees e ON e.employee_id = w.employee_id
WHERE NOT EXISTS((SELECT p.project_id
                 FROM projects p
                 WHERE p.start_date BETWEEN TO_DATE('2006/01/01', 'yyyy/mm/dd')
                 AND TO_DATE('2006/06/30', 'yyyy/mm/dd'))
                 MINUS
                 (SELECT p1.project_id
                  FROM projects p1, works_on w1
                  WHERE p1.project_id = w1.project_id
                  AND w1.employee_id = w.employee_id));

--2
SELECT 
    p.project_id, COUNT(w.employee_id)
FROM projects p
JOIN works_on w ON w.project_id = p.project_id
WHERE 
    w.employee_id IN
        (
        SELECT
            DISTINCT w.employee_id
        FROM works_on w
        WHERE 
            (
                SELECT
                    COUNT(DISTINCT jh.job_id)
                FROM job_history jh
                WHERE jh.employee_id = w.employee_id
                    AND jh.job_id <> (
                                        SELECT
                                            e.job_id
                                        FROM employees e
                                        WHERE e.employee_id = jh.employee_id
                                     )
            ) >= 2
        )
GROUP BY p.project_id
HAVING COUNT(w.employee_id) = 
    (
        SELECT
            COUNT(DISTINCT w.employee_id)
        FROM works_on w
        WHERE 
            (
                SELECT
                    COUNT(DISTINCT jh.job_id)
                FROM job_history jh
                WHERE jh.employee_id = w.employee_id
                    AND jh.job_id <> (
                                        SELECT
                                            e.job_id
                                        FROM employees e
                                        WHERE e.employee_id = jh.employee_id
                                     )
            ) >= 2
    );

--3
SELECT
    e.employee_id
FROM employees e
WHERE 
    (
        SELECT
            COUNT(j.job_id)
        FROM job_history j
        WHERE e.employee_id = j.employee_id AND e.job_id <> j.job_id
    ) >= 2 AND e.job_id IS NOT NULL;

--4
SELECT
    c.country_name, COUNT(e.employee_id)
FROM COUNTRIES c
LEFT JOIN LOCATIONS l ON l.country_id = c.country_id
LEFT JOIN departments d ON d.location_id = l.location_id
LEFT JOIN employees e ON e.department_id = d.department_id
GROUP BY c.country_name;

--5
SELECT
    DISTINCT w.employee_id
FROM works_on w
WHERE 
    (
        SELECT
            COUNT(*)
        FROM projects p
        JOIN works_on w2 ON w2.project_id = p.project_id
        WHERE p.DELIVERY_DATE > p.DEADLINE AND w2.employee_id = w.employee_id
    ) >= 2;

WITH proiecte AS (
    SELECT
        project_id
    FROM projects
    WHERE deadline < delivery_date
),
angajati AS(
    SELECT
        w.employee_id,
        p.project_id
    FROM works_on w
    JOIN proiecte p ON p.project_id = w.project_id
),
angajati2 AS (
    SELECT
        employee_id
    FROM angajati
    GROUP BY employee_id
    HAVING COUNT(project_id) >= 2
)
SELECT
    a.employee_id,
    e.last_name
FROM angajati2 a
JOIN employees e ON e.employee_id = a.employee_id;

--6
SELECT
    e.employee_id, e.first_name, w.project_id
FROM employees e
LEFT JOIN works_on w ON e.employee_id = w.employee_id;

--7
WITH t AS (
    SELECT
        DISTINCT p.project_manager
    FROM projects p
)
SELECT
    e.employee_id
FROM employees e
WHERE e.department_id IN
    (
        SELECT
            d.department_id
        FROM employees d
        WHERE d.employee_id IN
            (
                SELECT
                    project_manager
                FROM t
            )
    ) AND
    e.employee_id NOT IN 
        (
            SELECT
                project_manager
            FROM t
        );

--8
SELECT
    e.employee_id
FROM employees e
MINUS
SELECT
    e.employee_id
FROM employees e
WHERE 
    (
        SELECT
            COUNT(*)
        FROM employees e1
        JOIN projects p ON e1.employee_id = p.project_manager
        WHERE e1.department_id = e.department_id AND e.employee_id <> e1.employee_id
    ) >= 1;

--10
WITH t as
(
SELECT
    p.project_manager
FROM employees e
JOIN projects p ON e.employee_id = p.project_manager
GROUP BY p.project_manager
HAVING COUNT(p.project_manager) = 2)

SELECT
    *
FROM employees e
JOIN t ON e.employee_id = t.project_manager;

SELECT
    e.employee_id,
    e.first_name
FROM employees e
WHERE 
    e.employee_id IN
    (
        SELECT
            project_manager
        FROM projects
        GROUP BY project_manager
        HAVING COUNT(*) = 2
    );

SELECT * 
FROM employees e
WHERE 
    (
        SELECT
            COUNT(*)
        FROM projects p
        WHERE p.project_manager = e.employee_id
    ) = 2; 

--11
SELECT
    e.employee_id
FROM employees e
JOIN works_on w ON e.employee_id = w.employee_id
WHERE w.project_id IN
    (
        SELECT
            p.project_id
        FROM projects p
        WHERE p.project_manager = 102
    )
MINUS
SELECT
    e.employee_id 
FROM employees e
JOIN works_on w ON e.employee_id = w.employee_id
WHERE w.project_id IN
    (
        SELECT
            p.project_id
        FROM projects p
        WHERE p.project_manager <> 102
    );

--12
--a
SELECT
    DISTINCT w.employee_id
FROM works_on w
WHERE 
    NOT EXISTS
        (
            (
                SELECT
                    w1.project_id
                FROM works_on w1
                WHERE w1.employee_id = 200
            )
            MINUS
            (
                SELECT
                    w1.project_id
                FROM works_on w1
                WHERE w1.employee_id = W.EMPLOYEE_ID
            )
        ) AND w.employee_id <> 200;
    
--b
SELECT
    DISTINCT w.employee_id
FROM works_on w
WHERE 
    NOT EXISTS
        (
            (
                SELECT
                    w1.project_id
                FROM works_on w1
                WHERE w1.employee_id = W.EMPLOYEE_ID
            )
            MINUS
            (
                SELECT
                    w1.project_id
                FROM works_on w1
                WHERE w1.employee_id = 200
            )
        ) AND w.employee_id <> 200;

--13
SELECT
    DISTINCT w.employee_id
FROM works_on w
WHERE (NOT EXISTS
                (
                    (
                        SELECT
                            b.project_id
                        FROM works_on b
                        WHERE b.employee_id = 200
                    )
                    MINUS
                    (
                        SELECT
                            b.project_id
                        FROM works_on b
                        WHERE w.employee_id = b.employee_id
                    )
                ))
        AND
        (
        NOT EXISTS
                (
                    (
                        SELECT
                            b.project_id
                        FROM works_on b
                        WHERE w.employee_id = b.employee_id
                    )
                    MINUS
                    (
                        SELECT
                            b.project_id
                        FROM works_on b
                        WHERE b.employee_id = 200
                    )
        )
        )
        AND w.employee_id <>200
        ;


--14
SELECT
    e.first_name, e.last_name,
    e.salary, jg.grade_level
FROM employees e
JOIN job_grades jg ON 
    e.salary < jg.highest_sal AND
    e.salary > jg.lowest_sal;

--VARIABILE DE SUBSTITUTIE
--DEFINE + && -> salveaza variabila in baza de date 
--            -> poate fi accesata oricand cu & sau &&
-- & -> nu salveaza variabila in baza de date
--   -> valoarea variabilei poate fi folosita doar la momentul aparitiei acesteia

--aici trb introdusa de fiecare data valoarea pt p_coloana
SELECT &p_coloana 
FROM &p_tabel
WHERE &p_where
ORDER BY &p_coloana;

--aici trb introdusa o sg data, la prima aparitie
-- vede '&&' (linia 1), asa ca va salva variabila in baza de date, iar cand o sa o vada iar (linia 4) o va gasi deja in baza de date si nu mai trb introdusa din nou valoarea
SELECT &&p_coloana 
FROM &p_tabel
WHERE &p_where
ORDER BY &p_coloana;

--9
SELECT
    department_id
FROM employees e
GROUP BY department_id
HAVING AVG(e.salary) > &val;

--18
SELECT
    e.employee_id
FROM employees e
WHERE LOWER(e.job_id) = &job;

--19
SELECT
    e.employee_id
FROM employees e
WHERE hire_date > &hd;

--20
SELECT &&p_coloana 
FROM &p_tabel
WHERE &p_where
ORDER BY &p_coloana;

--21
ACCEPT h1 PROMPT 'h1= ';
ACCEPT h2 PROMPT 'h2= ';
SELECT
    employee_id,
    TO_CHAR(hire_date, 'MM/DD/YY')
FROM employees
WHERE 
    TO_DATE(TO_CHAR(hire_date, 'MM/DD/YY'), 'MM/DD/YY')  
    BETWEEN TO_DATE(&h1, 'MM/DD/YY') AND 
        TO_DATE(&h2, 'MM/DD/YY');

--22
SELECT
    employee_id
FROM employees
JOIN departments USING (department_id)
JOIN locations USING (location_id)
WHERE LOWER(city) = &oras;