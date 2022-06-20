SELECT * FROM DUAl;

CREATE TABLE client(
    id_client NUMBER(6) primary key,
    nume VARCHAR2(50),
    prenume VARCHAR2(50) NOT NULL,
    id_adresa NUMBER(6),
    email VARCHAR2(255) NOT NULL,
    data date DEFAULT current_date
);


CREATE TABLE ticket(
    id_ticket NUMBER(6) primary key,
    titlu VARCHAR2(256) NOT NULL,
    continut NVARCHAR2(2000) NOT NULL,
    id_client NUMBER(6) NOT NULL,
    id_angajat NUMBER(6)
);


CREATE TABLE adresa(
    id_adresa NUMBER(6) primary key,
    oras VARCHAR2(50) NOT NULL,
    strada VARCHAR2(256) NOT NULL,
    numar NUMBER(4) NOT NULL,
    apartament NUMBER(4),
    cod_postal VARCHAR2(10) NOT NULL
);

CREATE TABLE angajat(
    id_angajat NUMBER(6) primary key,
    nume VARCHAR2(50) NOT NULL,
    prenume VARCHAR2(50) NOT NULL,
    id_adresa NUMBER(6) NOT NULL,
    id_departament NUMBER(6),
    email VARCHAR2(255) NOT NULL,
    data_angajare date DEFAULT current_date,
    salariu NUMBER(6) DEFAULT 3000
);

CREATE TABLE departament(
    id_departament NUMBER(6) primary key,
    titlu VARCHAR2(50) NOT NULL,
    id_adresa NUMBER(6),
    email VARCHAR2(255) NOT NULL,
    id_manager NUMBER(6) DEFAULT 1
);
DROP TABLE produs PURGE;

CREATE TABLE producator(
    id_producator NUMBER(6) primary key,
    nume VARCHAR2(50) NOT NULL,
    descriere NVARCHAR2(2000),
    id_adresa NUMBER(6) ,
    email VARCHAR2(255) NOT NULL
);

CREATE TABLE produs(
    id_produs NUMBER(6) PRIMARY KEY,
    id_producator NUMBER(6) NOT NULL,
    stoc NUMBER(6) CHECK ( stoc >= 0 ),
    pret NUMBER(8,2) CHECK ( pret >= 0 ),
    nume VARCHAR2(50) NOT NULL,
    descriere NVARCHAR2(2000),
    tip VARCHAR2(10) CHECK( tip IN ('microfon','casti') ),
    id_reducere NUMBER(6)
);

CREATE TABLE microfon(
    id_produs NUMBER(6) NOT NULL,
    id_microfon NUMBER(6) PRIMARY KEY,
    tip VARCHAR2(20) CHECK( tip IN ('dinamic','condensator') ),
    conectivitate VARCHAR2(20) CHECK( conectivitate IN ('XLR','USB', 'JACK') )
);

CREATE TABLE casti(
    id_produs NUMBER(6) NOT NULL,
    id_casti NUMBER(6) PRIMARY KEY,
    tip VARCHAR2(20) CHECK( tip IN ('In Ear','Over Ear','On Ear') ),
    conectivitate VARCHAR2(20) CHECK( conectivitate IN ('wireless','cu fir') ),
    noise_cancelling NUMBER(1)
);

CREATE TABLE produs_comandat(
    id_produs NUMBER(6) NOT NULL,
    id_comanda NUMBER(6) NOT NULL,
     PRIMARY KEY (id_produs, id_comanda)
);

CREATE TABLE produs_comandat(
    id_produs NUMBER(6) NOT NULL,
    id_comanda NUMBER(6) NOT NULL,
     PRIMARY KEY (id_produs, id_comanda)
);

CREATE TABLE comanda(
    id_comanda NUMBER(6) PRIMARY KEY,
    id_client NUMBER(6) NOT NULL,
    mentiuni NVARCHAR2(2000),
    id_adresa NUMBER(6),
    id_angajat NUMBER(6)
);


CREATE TABLE reducere(
    id_reducere NUMBER(6) primary key,
    data_inceput date DEFAULT current_date,
    data_sfarsit date DEFAULT current_date,
    tip VARCHAR2(10) CHECK( tip IN ('procent','suma') ),
    valoare NUMBER(5) DEFAULT 0 CHECK ( valoare >= 0 )
);
