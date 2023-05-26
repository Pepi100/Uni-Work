SELECT * FROM DUAl;


CREATE TABLE address(
                        address_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                        city VARCHAR2(50) NOT NULL,
                        country VARCHAR2(50) NOT NULL,
                        street VARCHAR2(255) NOT NULL,
                        "NUMBER" NUMBER(6)
);

CREATE TABLE manufacturer(
                             manufacturer_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                             name VARCHAR2(50) NOT NULL,
                             email VARCHAR2(50)
);


CREATE TABLE product(
                        product_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                        manufacturer_id NUMBER(6) NOT NULL,
                        price NUMBER(8,2) CHECK ( price >= 0 ),
                        name VARCHAR2(50) NOT NULL
);

CREATE TABLE microphone(
                           product_id NUMBER(6) NOT NULL,
                           microphone_id  NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                           capsule VARCHAR2(20) CHECK( capsule IN ('DYNAMIC','CONDENSER') ),
                           MicConnectivityType VARCHAR2(20) CHECK( MicConnectivityType IN ('XLR','USB', 'JACK') )
);

CREATE TABLE headphones (
                            product_id NUMBER(6) NOT NULL,
                            headphones_id  NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                            FitType VARCHAR2(20) CHECK( FitType IN ('ON_EAR','OVER_EAR','IN_EAR') ),
                            ConnectivityType VARCHAR2(20) CHECK( ConnectivityType IN ('WIRED','WIRELESS') ),
                            noise_cancelling NUMBER(1)
);

CREATE TABLE "USER"
(
    user_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
    name VARCHAR2(50) NOT NULL,
    email VARCHAR2(50) NOT NULL

);

CREATE TABLE employee(
                         employee_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                         user_id NUMBER(6) NOT NULL,
                         department VARCHAR2(50) NOT NULL

);

CREATE TABLE customer(
                         customer_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1),
                         user_id NUMBER(6) NOT NULL,
                         address_id NUMBER(6) NOT NULL

);



INSERT INTO address ( city,country, street, "NUMBER") VALUES ( 'Bucuresti','Romania','Alexandru Macedon', 20);



-- DROP table address;
