-- 1. Pentru fiecare chelner sa se afiseze meniule pe care l-a servit de cele mai multe ori.


WITH chelneri as (SELECT e.employee_id, e.last_name
                    FROM restaurant_employees e
                    JOIN restaurant_jobs j ON j.job_id = e.job_id
                    WHERE LOWER(j.job_name) = 'chelner' OR LOWER(j.job_name) = 'sef chelneri' ),
OMC as (SELECT c.employee_id, om.menu_id, COUNT(*) as "numar"
            FROM chelneri c
            JOIN orders o ON c.employee_id = o.employee_id
            JOIN order_menu om ON om.order_id = o.order_id
            GROUP BY c.employee_id, om.menu_id),
maxime as (SELECT c.employee_id, o.menu_id, o."numar" 
            FROM chelneri c
            LEFT JOIN OMC o ON o.employee_id = c.employee_id
            WHERE o."numar" = (SELECT MAX(omc."numar")
                                FROM OMC omc
                                WHERE omc.employee_id = c.employee_id
                                GROUP BY omc.employee_id) )
SELECT c.employee_id as "ID" , c.last_name as "Nume" ,
    CASE
        WHEN ( (SELECT COUNT(*) FROM maxime m WHERE m.employee_id = c.employee_id) = 0) THEN 'Nu a dus comenzi.'
        WHEN ( (SELECT COUNT(*) FROM maxime m WHERE m.employee_id = c.employee_id) > 1) THEN 'A dus ' || (SELECT COUNT(*) FROM maxime m WHERE m.employee_id = c.employee_id) || ' meniuri de numar maxim de ori.'
        ELSE  'Meniul cel mai des servit este ' || ( SELECT me.menu_name FROM maxime m JOIN menus me ON me.menu_id = m.menu_id  WHERE m.employee_id = c.employee_id)
    END as "Comanda cea mai servita"
FROM chelneri c;

                    

