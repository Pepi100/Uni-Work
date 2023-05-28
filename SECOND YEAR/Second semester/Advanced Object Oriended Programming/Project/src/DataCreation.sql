SELECT * FROM DUAl;


CREATE TABLE address(
                        address_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                        city VARCHAR2(50) NOT NULL,
                        country VARCHAR2(50) NOT NULL,
                        street VARCHAR2(255) NOT NULL,
                        streetNumber NUMBER(6)
);

CREATE TABLE manufacturer(
                             manufacturer_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) primary key ,
                             name VARCHAR2(50) NOT NULL,
                             email VARCHAR2(50)
);


CREATE TABLE product(
                        product_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                        manufacturer_id NUMBER(6)  ,
                        price NUMBER(8,2) CHECK ( price >= 0 ),
                        name VARCHAR2(50) NOT NULL,
                        CONSTRAINT fk_product
                            FOREIGN KEY( manufacturer_id )
                                REFERENCES manufacturer( manufacturer_id )
                                    ON DELETE CASCADE

);

CREATE TABLE microphone(
                           product_id NUMBER(6) NOT NULL,
                           microphone_id  NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                           capsule VARCHAR2(20) CHECK( capsule IN ('DYNAMIC','CONDENSER') ),
                           MicConnectivityType VARCHAR2(20) CHECK( MicConnectivityType IN ('XLR','USB', 'JACK') ),
                               CONSTRAINT fk_CONSTRAINT1
                               FOREIGN KEY( product_id )
                               REFERENCES product( product_id )
                               ON DELETE CASCADE
);

CREATE TABLE headphones (
                            product_id NUMBER(6) NOT NULL,
                            headphones_id  NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                            FitType VARCHAR2(20) CHECK( FitType IN ('ON_EAR','OVER_EAR','IN_EAR') ),
                            ConnectivityType VARCHAR2(20) CHECK( ConnectivityType IN ('WIRED','WIRELESS') ),
                            CONSTRAINT fk_CONSTRAINT2
                                FOREIGN KEY( product_id )
                                    REFERENCES product( product_id )
                                        ON DELETE CASCADE
);

CREATE TABLE "USER"
(
    user_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
    name VARCHAR2(50) NOT NULL,
    email VARCHAR2(50) NOT NULL

);

CREATE TABLE employee(
                         employee_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                         user_id NUMBER(6) NOT NULL,
                         department VARCHAR2(50) NOT NULL,
                         CONSTRAINT fk_CONSTRAINT3
                             FOREIGN KEY( user_id )
                                 REFERENCES "USER"( user_id )
                                     ON DELETE CASCADE

);

CREATE TABLE customer(
                         customer_id NUMBER GENERATED ALWAYS as IDENTITY(START with 1 INCREMENT by 1) PRIMARY KEY,
                         user_id NUMBER(6) NOT NULL,
                         address_id NUMBER(6) NOT NULL,
                         CONSTRAINT fk_CONSTRAINT4 FOREIGN KEY( user_id ) REFERENCES "USER"( user_id )ON DELETE CASCADE,
                        CONSTRAINT fk_CONSTRAINT5  FOREIGN KEY( address_id ) REFERENCES address( address_id ) ON DELETE CASCADE

);

insert into address (city, country, street, streetNumber) VALUES ('sdsd', 'sdsd','sdsd',22 );


TRUNCATE TABLE address;
TRUNCATE TABLE customer;
TRUNCATE TABLE "USER";
TRUNCATE TABLE address;

drop table headphones;
drop table microphone;
drop table product;
drop table "USER";
drop table employee;
drop table customer;
drop table address;
drop table manufacturer;
;


DROP table address;
