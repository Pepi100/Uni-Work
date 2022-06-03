DROP TYPE IF EXISTS subcategorie;
DROP TYPE IF EXISTS tipuri_Microfon;

CREATE TYPE subcategorie AS ENUM( 'Microfon de voce si live', 'Microfon de studio', 'Microfon lavaliera', 'Microfon gaming / podcast', 'Microfon pentru camere video');
CREATE TYPE tipuri_Microfon AS ENUM('Stereo', 'Dinamic', 'Condenser');


CREATE TABLE IF NOT EXISTS microfoane (
   id serial PRIMARY KEY,
   nume VARCHAR(50) UNIQUE NOT NULL,
   descriere TEXT,
   pret NUMERIC(8,2) NOT NULL,
   an_fabricatie INT NOT NULL CHECK (an_fabricatie>=1800),   
   tip tipuri_Microfon DEFAULT 'Dinamic',
   producator VARCHAR(30),
   categorie subcategorie DEFAULT 'Microfon de voce si live',
   dimensiuni INT[], --pot sa nu fie specificare deci nu punem NOT NULL
   incl_cablu BOOLEAN NOT NULL DEFAULT FALSE,
   imagine VARCHAR(300),
   data_adaugare TIMESTAMP DEFAULT current_timestamp
);


INSERT into microfoane (nume, producator, descriere, pret, an_fabricatie, categorie, tip, dimensiuni, incl_cablu, imagine) VALUES 
('AT2035','Audio-Technica', 'Nimic', 429, '2008', 'Microfon gaming / podcast', 'Condenser', '{40,12,20}', True,'at2035.jpg'),
('ATR2500X-USB','Audio-Technica', 'Nimic', 549, '2019', 'Microfon de studio', 'Condenser', '{15,5,20}', True,'atr2500x-usb.jpg'),
('BY-M1','Boya', 'Nimic', 69, '2014', 'Microfon lavaliera', 'Condenser', '{13,5,10}', True,'by-m1.jpg'),
('BY-MM1','Boya', 'Microfon Cardioid TRS / TRRS pt Smartphone, Camera, PC BOYA BY-MM1. Include filtru anti-vant.', 139, '2014', 'Microfon lavaliera', 'Condenser', '{13,5,10}', True,'by-mm1.jpg'),
('C-1U','Behringer', 'Behringer C-1U este un microfon condenser de studio cu conexiune prin USB.', 229, '2009', 'Microfon de studio', 'Condenser', '{40,12,20}', True,'c-1u.jpg'),
('ECO-88S','Superlux', 'Superlux ECO 88S este un microfon de voce, cardioid, cu un design atractiv, constructie solida si ce ofera o frecventa larga de raspuns si o sensibilitate mare.', 48, '2014', 'Microfon de voce si live', 'Condenser', '{20,5,5}', False,'eco-88s.jpg'),
('Lavalier Go','Rode', 'Nimic', 299, '2020', 'Microfon lavaliera', 'Condenser', '{}', True,'lavalier-go.jpg'),
('Lavalier Go-W','Rode', 'Nimic', 325, '2020', 'Microfon lavaliera', 'Condenser', '{}', True,'lavalier-go-w.jpg'),
('MKE-200','SENNHEISER', 'MKE200 este un microfon compact cu condensator pentru camere video sau telefoane, echipat cu un conector de intrare jack de 3,6 mm.', 456, '2020', 'Microfon pentru camere video', 'Condenser', '{7,10,5}', True,'mke-200.jpg'),
('Podcaster','Rode', 'Sunet de calitate Broadcast; Capsula dinamica de 28mm;', 898, '2018', 'Microfon gaming / podcast', 'Dinamic', '{21,6,6}', False,'podcaster.jpg'),
('PodMic','Rode', 'PodMic este un microfon dinamic cu calitate de broadcast optimizat pentru podcast-uri.', 555, '2019', 'Microfon gaming / podcast', 'Dinamic', '{}', False,'podmic.jpg'),
('SM-57','Shure', 'Microfonul dinamic cardioid SM57 ofera o reproducere curata a instrumentelor amplificate si acustice.', 489, '1965', 'Microfon de voce si live', 'Dinamic', '{15,3}', False,'sm-57.jpg'),
('SM-58S','Shure', 'Legendarul Shure SM58S este un microfon dinamic de voce construit in special pentru interpretari live in concerte sau dedicat inregistrarilor in studio', 529, '1966', 'Microfon de voce si live', 'Dinamic', '{16,5}', False,'sm58-s.jpg'),
('TM58','Superlux', 'Microfon vocal dinamic, cardioid, cu design si sunet clasic.', 129, '2019', 'Microfon de voce si live', 'Dinamic', '{}', False,'tm58.jpg'),
('VideoMic GO','Rode', 'Rode VideoMic GO este un microfon compact pentru camere DSLR sau pentru camere foto-video dotate cu mufa jack de 3.5 pentru microfon exterior.', 299, '2013', 'Microfon pentru camere video', 'Condenser', '{}', True,'videomic-go.jpg');





SELECT * FROM public.microfoane
