DROP TYPE IF EXISTS categ_nivel;
DROP TYPE IF EXISTS tipuri_produse;

CREATE TYPE categ_nivel AS ENUM( 'profesional', 'amator', 'studio');
CREATE TYPE tipuri_produse AS ENUM('microfon', 'casti', 'accesoriu', 'interfata');


CREATE TABLE IF NOT EXISTS produse (
   id serial PRIMARY KEY,
   nume VARCHAR(50) UNIQUE NOT NULL,
   descriere TEXT,
   pret NUMERIC(8,2) NOT NULL,
   an_fabricatie INT NOT NULL CHECK (an_fabricatie>=0),   
   tip_produs tipuri_produse DEFAULT 'microfon',
   producator VARCHAR(30) NOT NULL,
   categorie categ_nivel DEFAULT 'amator',
   dimensiuni INT[], --pot sa nu fie specificare deci nu punem NOT NULL
   incl_cablu BOOLEAN NOT NULL DEFAULT FALSE,
   imagine VARCHAR(300),
   data_adaugare TIMESTAMP DEFAULT current_timestamp
);

INSERT into produse (nume,producator,descriere,pret, an_fabricatie, tip_produs, categorie, dimensiuni, incl_cablu, imagine) VALUES 
('SM7B','Shure', 'Super Microfon', 1700, '2001', 'microfon', 'profesional', '{63,50,189}', False,'shure-super-55-deluxe.jpg'),
('AT2040','Audio-Technica', 'Nimic', 429, '2021', 'microfon', 'amator', '{40,12,20}', True,'audio-technica-at2040.jpg'),
('AT2035','Audio-Technica', 'Nimic', 429, '2008', 'microfon', 'amator', '{40,12,20}', True,'audio-technica-at2035.jpg');




SELECT * FROM public.produse
