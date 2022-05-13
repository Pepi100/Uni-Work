SELECT (TO_DATE(&&start_date,'dd/mm/yyyy') + rownum -1 )as "Zile Calendaristice"
FROM dual
CONNECT BY rownum <= (TO_DATE(&end_date,'dd/mm/yyyy') - TO_DATE(&start_date,'dd/mm/yyyy') + 1);

