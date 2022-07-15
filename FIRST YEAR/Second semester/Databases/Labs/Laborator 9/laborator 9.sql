--1
DROP TABLE angajati2_pnu;
CREATE TABLE angajati2_pnu(
    cod_ang number(4), 
    nume varchar2(20) not null,
    prenume varchar2(20), 
    email char(15), 
    data_ang date DEFAULT SYSDATE, 
    job varchar2(20), 
    cod_sef number(4), 
    salariu number(8,2) NOT NULL, 
    cod_dep number(2),
    PRIMARY KEY (cod_ang)
); 

--2
INSERT INTO angajati2_pnu 
VALUES (100, 'nume1', 'prenume1', NULL, 'director', NULL, 20000, 10);

--INSERT INTO angajati2_pnu (cod_ang, nume, prenume, job, salariu, cod_dep)
--VALUES (100, 'nume1', 'prenume1', 'director', 20000, 10);

INSERT INTO angajati2_pnu
VALUES (101, 'nume2', 'prenume2', 'nume2', '02-FEB-2014', 'inginer', 100, 10000, 10);

INSERT INTO angajati2_pnu
VALUES (102, 'nume3', 'prenume3', 'nume3', '05-JUN-2010', 'programator', 101, 5000, 20);

INSERT INTO angajati2_pnu
VALUES (103, 'nume4', 'prenume4', NULL, NULL, 'inginer', 100, 9000, 20);

INSERT INTO angajati2_pnu
VALUES (104, 'nume5', 'prenume5', 'nume5', NULL, 'programator', 101, 3000, 30);
SELECT * FROM angajati2_pnu;

--3
DROP TABLE angajati101_pnu;
CREATE TABLE angajati101_pnu AS
(SELECT * FROM angajati2_pnu WHERE cod_dep = 10);

SELECT * FROM angajati101_pnu;

--4
ALTER TABLE angajati2_pnu
ADD comision NUMBER(4, 2);

--5
--NU E POSIBILA MODIFICAREA (salariu are NUMBER(8,2) SI NU POATE SA SCADA LA NUMBER(6,2))
--AR FI MERS MODIFICAREA DACA NU AR FI FOST INREGISTRARI IN TABEL SAU DACA PE COLOANA 'salariu' TOATE INREGISTRARILE AR FI AVUT VALOAREA NULL
ALTER TABLE angajati2_pnu
MODIFY salariu NUMBER(6, 2);

--6
ALTER TABLE angajati2_pnu
MODIFY salariu DEFAULT 1000;

--7
ALTER TABLE angajati2_pnu
MODIFY (
    salariu NUMBER(10, 2), --IN ACEST CAZ MERGE MODIFICAREA DEOARECE SE CRESTE DE LA 8->10
    comision NUMBER(2, 2) --IN ACEST CAZ MERGE DEOARECE PE COLOANA 'comision'  TOATE INREGISTRARILE AU NULL
);

--8
UPDATE angajati2_pnu
SET comision = 0.1
WHERE LOWER(job) LIKE 'i%';

SELECT * FROM angajati2_pnu;

--9
ALTER TABLE angajati2_pnu
MODIFY email VARCHAR(100);

--10
ALTER TABLE angajati2_pnu
ADD nr_telefon CHAR(10) DEFAULT '111';

--11
ALTER TABLE angajati2_pnu
DROP COLUMN nr_telefon;

--12
RENAME angajati2_pnu TO angajati3_pnu;

--13
SELECT * FROM TAB;
RENAME angajati3_pnu TO angajati2_pnu;

--14
TRUNCATE TABLE angajati2_pnu;

DELETE FROM angajati2_pnu
WHERE 1=1;

--15
CREATE TABLE departamente2_pnu (
    cod_dep number(2), 
    nume varchar2(15) NOT NULL, 
    cod_director number(4)
);

--16
INSERT INTO departamente2_pnu
VALUES (10, 'administrativ', 100);
INSERT INTO departamente2_pnu
VALUES (20, 'proiectare', 101);
INSERT INTO departamente2_pnu
VALUES (30, 'programare', NULL);

--17
ALTER TABLE departamente2_pnu
ADD CONSTRAINT pk PRIMARY KEY (cod_dep);

--18
ALTER TABLE angajati2_pnu
ADD (
    CONSTRAINT fk2 FOREIGN KEY (cod_dep) REFERENCES departamente2_pnu (cod_dep),
    CONSTRAINT fk22 FOREIGN KEY (cod_sef) REFERENCES angajati2_pnu (cod_ang),
    CONSTRAINT unq2 UNIQUE (nume, prenume),
    CONSTRAINT unq_email2 UNIQUE (email),
    CONSTRAINT ch12 CHECK (cod_dep > 0),
    CONSTRAINT ch22 CHECK (salariu > comision * 100)
);

ALTER TABLE angajati2_pnu
MODIFY nume NOT NULL; --VA DA EROARE DEOARECE 'nume' ESTE DEJA NOT NULL

--21
DROP TABLE departamente_pnu;

--23
SELECT constraint_name, constraint_type, table_name
FROM user_constraints
WHERE lower(table_name) IN ('angajati2_pnu', 'departamente2_pnu');

--24
ALTER TABLE angajati2_pnu
MODIFY email NOT NULL;

--25
--VA DA EROARE DEOARECE NU EXISTA DEPARTAMENTUL '50' (integrity constraint (GRUPA151.FK_COD_DEP2) violated - parent key not found)
INSERT INTO angajati2_pnu 
VALUES (110, 'nume11', 'prenume11', NULL, NULL, 'director', NULL, 20000, 50, 0.1);

--26
INSERT INTO departamente2_pnu
VALUES (60, 'testare', NULL);
COMMIT;

--27
--NU VA FUNCTIONA DEOARECE EXISTA ANGAJATI IN 'angajati2_pnu' CARE SUNT DIN DEPARTAMENTUL '20' (integrity constraint (GRUPA151.FK_COD_SEF2) violated - child record found)
DELETE FROM departamente2_pnu
WHERE COD_DEP = 20;

--28
--VA FUNCTIONA DEOARECE NU EXISTA ANGAJATI IN 'angajati2_pnu' CARE SUNT DIN DEPARTAMENTUL '60'
DELETE FROM departamente2_pnu
WHERE COD_DEP = 60;

--29
INSERT INTO angajati2_pnu 
VALUES (114, 'nume13', 'prenume13', NULL, NULL, 'director', 100, 20000, 10, 0.1);

INSERT INTO angajati2_pnu 
VALUES (110, 'nume14', 'prenume14', NULL, NULL, 'director', 114, 20000, 10, 0.1);

--31
ALTER TABLE angajati2_pnu
ADD CONSTRAINT fk2 FOREIGN KEY (cod_dep) REFERENCES
    departamente2_pnu(cod_dep) ON DELETE CASCADE;

--32
--CHIAR DACA EXISTA ANGAJATI IN DEP20, STERGEREA VA FUNCTIONA DEOARECE S-A ADAUGAT LA CONSTRANGEREA DE TIP FOREIGN KEY DE MAI SUS 
--EXPRESIA 'ON DELETE CASCADE' CARE VA STERGE SI INREGSITRARILE CORESPUNZATOARE DIN 'angajati2_pnu'
SELECT * FROM angajati2_pnu;
DELETE FROM departamente2_pnu
WHERE cod_dep = 20;

SELECT * FROM departamente2_pnu;

--33 + 34
--LA FEL CA LA EX ANTERIOR, STERGEREA VA FUNCTIONA, DOAR CA ACUM IN LOC SA FIE STERSE INREGISTRARILE CORESP DIN 'angajati2_pnu',
--VOR AVEA VALOAREA 'NULL' SETATA PE COLOANA CARE FACE LEGATURA
ALTER TABLE departamente2_pnu
ADD CONSTRAINT fk3 FOREIGN KEY (cod_director) 
    REFERENCES angajati2_pnu (cod_ang) ON DELETE SET NULL;

SELECT * FROM departamente2_pnu;
SELECT * FROM angajati2_pnu;

UPDATE departamente2_pnu
SET cod_director = 104
WHERE COD_DEP = 30;

DELETE FROM angajati2_pnu
WHERE cod_ang = 104;

--35
ALTER TABLE angajati2_pnu
ADD CONSTRAINT ch3 CHECK(salariu < 30000);

--36
--NU VA FUNCTIONA DIN CAUZA CONSTRANGERII
UPDATE angajati2_pnu
SET salariu = 35000
WHERE cod_ang = 100;

--37
ALTER TABLE angajati2_pnu
MODIFY CONSTRAINT ch3 DISABLE;

--ACUM VA FUNCTIONA DEOARECE CONSTRANGEREA A FOST OPRITA
UPDATE angajati2_pnu
SET salariu = 35000
WHERE cod_ang = 100;

--NU VA FUNCTIONA DEOARECE EXISTA ANGAJATUL ADAUGAT ANTERIOR CARE NU RESPECTA COSTRANGEREA
ALTER TABLE angajati2_pnu
MODIFY CONSTRAINT ch3 ENABLE;