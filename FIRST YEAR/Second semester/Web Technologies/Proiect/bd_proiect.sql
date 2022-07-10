f--
-- PostgreSQL database dump
--

-- Dumped from database version 14.2
-- Dumped by pg_dump version 14.2

-- Started on 2022-07-04 19:20:28

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 836 (class 1247 OID 16427)
-- Name: categ_nivel; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.categ_nivel AS ENUM (
    'profesional',
    'amator',
    'studio'
);


ALTER TYPE public.categ_nivel OWNER TO postgres;

--
-- TOC entry 854 (class 1247 OID 24597)
-- Name: roluri; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.roluri AS ENUM (
    'admin',
    'moderator',
    'comun'
);


ALTER TYPE public.roluri OWNER TO postgres;

--
-- TOC entry 845 (class 1247 OID 16498)
-- Name: subcategorie; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.subcategorie AS ENUM (
    'Microfon de voce si live',
    'Microfon de studio',
    'Microfon lavaliera',
    'Microfon gaming / podcast',
    'Microfon pentru camere video'
);


ALTER TYPE public.subcategorie OWNER TO postgres;

--
-- TOC entry 848 (class 1247 OID 16510)
-- Name: tipuri_microfon; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.tipuri_microfon AS ENUM (
    'Stereo',
    'Dinamic',
    'Condenser'
);


ALTER TYPE public.tipuri_microfon OWNER TO postgres;

--
-- TOC entry 839 (class 1247 OID 16434)
-- Name: tipuri_produse; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE public.tipuri_produse AS ENUM (
    'microfon',
    'casti',
    'accesoriu',
    'interfata'
);


ALTER TYPE public.tipuri_produse OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 218 (class 1259 OID 24618)
-- Name: accesari; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.accesari (
    id integer NOT NULL,
    ip character varying(100) NOT NULL,
    user_id integer,
    pagina character varying(500) NOT NULL,
    data_accesare timestamp without time zone DEFAULT CURRENT_TIMESTAMP
);


ALTER TABLE public.accesari OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 24617)
-- Name: accesari_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.accesari_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.accesari_id_seq OWNER TO postgres;

--
-- TOC entry 3401 (class 0 OID 0)
-- Dependencies: 217
-- Name: accesari_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.accesari_id_seq OWNED BY public.accesari.id;


--
-- TOC entry 220 (class 1259 OID 32796)
-- Name: jucarii; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.jucarii (
    id_jucarii integer NOT NULL,
    nume text NOT NULL,
    pret integer,
    varsta_minima integer,
    culori character varying[],
    data_adaugare timestamp without time zone DEFAULT CURRENT_TIMESTAMP
);


ALTER TABLE public.jucarii OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 32795)
-- Name: jucarii_id_jucarii_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.jucarii_id_jucarii_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.jucarii_id_jucarii_seq OWNER TO postgres;

--
-- TOC entry 3404 (class 0 OID 0)
-- Dependencies: 219
-- Name: jucarii_id_jucarii_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.jucarii_id_jucarii_seq OWNED BY public.jucarii.id_jucarii;


--
-- TOC entry 214 (class 1259 OID 16518)
-- Name: microfoane; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.microfoane (
    id integer NOT NULL,
    nume character varying(50) NOT NULL,
    descriere text,
    pret numeric(8,2) NOT NULL,
    an_fabricatie integer NOT NULL,
    tip public.tipuri_microfon DEFAULT 'Dinamic'::public.tipuri_microfon,
    producator character varying(30),
    categorie public.subcategorie DEFAULT 'Microfon de voce si live'::public.subcategorie,
    dimensiuni integer[],
    incl_cablu boolean DEFAULT false NOT NULL,
    imagine character varying(300),
    data_adaugare timestamp without time zone DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT microfoane_an_fabricatie_check CHECK ((an_fabricatie >= 1800))
);


ALTER TABLE public.microfoane OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 16517)
-- Name: microfoane_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.microfoane_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.microfoane_id_seq OWNER TO postgres;

--
-- TOC entry 3406 (class 0 OID 0)
-- Dependencies: 213
-- Name: microfoane_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.microfoane_id_seq OWNED BY public.microfoane.id;


--
-- TOC entry 212 (class 1259 OID 16444)
-- Name: produse; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.produse (
    id integer NOT NULL,
    nume character varying(50) NOT NULL,
    descriere text,
    pret numeric(8,2) NOT NULL,
    an_fabricatie integer NOT NULL,
    tip_produs public.tipuri_produse DEFAULT 'microfon'::public.tipuri_produse,
    producator character varying(30) NOT NULL,
    categorie public.categ_nivel DEFAULT 'amator'::public.categ_nivel,
    dimensiuni character varying[],
    incl_cablu boolean DEFAULT false NOT NULL,
    imagine character varying(300),
    data_adaugare timestamp without time zone DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT produse_an_fabricatie_check CHECK ((an_fabricatie >= 0))
);


ALTER TABLE public.produse OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 16443)
-- Name: produse_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.produse_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.produse_id_seq OWNER TO postgres;

--
-- TOC entry 3409 (class 0 OID 0)
-- Dependencies: 211
-- Name: produse_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.produse_id_seq OWNED BY public.produse.id;


--
-- TOC entry 210 (class 1259 OID 16396)
-- Name: tabel; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.tabel (
    id integer NOT NULL,
    nume character varying(100) NOT NULL,
    pret integer DEFAULT 69
);


ALTER TABLE public.tabel OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 16395)
-- Name: tabel_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.tabel ALTER COLUMN id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.tabel_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 216 (class 1259 OID 24604)
-- Name: utilizatori; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.utilizatori (
    id integer NOT NULL,
    username character varying(50) NOT NULL,
    nume character varying(100) NOT NULL,
    prenume character varying(100) NOT NULL,
    parola character varying(500) NOT NULL,
    rol public.roluri DEFAULT 'comun'::public.roluri NOT NULL,
    email character varying(100) NOT NULL,
    culoare_chat character varying(50) NOT NULL,
    data_adaugare timestamp without time zone DEFAULT CURRENT_TIMESTAMP,
    cod character varying(200),
    confirmat_mail boolean DEFAULT false,
    tema character varying(50),
    ocupatie character varying(50)[]
);


ALTER TABLE public.utilizatori OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 24603)
-- Name: utilizatori_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.utilizatori_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.utilizatori_id_seq OWNER TO postgres;

--
-- TOC entry 3414 (class 0 OID 0)
-- Dependencies: 215
-- Name: utilizatori_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.utilizatori_id_seq OWNED BY public.utilizatori.id;


--
-- TOC entry 3221 (class 2604 OID 24621)
-- Name: accesari id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accesari ALTER COLUMN id SET DEFAULT nextval('public.accesari_id_seq'::regclass);


--
-- TOC entry 3223 (class 2604 OID 32799)
-- Name: jucarii id_jucarii; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jucarii ALTER COLUMN id_jucarii SET DEFAULT nextval('public.jucarii_id_jucarii_seq'::regclass);


--
-- TOC entry 3211 (class 2604 OID 16521)
-- Name: microfoane id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.microfoane ALTER COLUMN id SET DEFAULT nextval('public.microfoane_id_seq'::regclass);


--
-- TOC entry 3205 (class 2604 OID 16447)
-- Name: produse id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produse ALTER COLUMN id SET DEFAULT nextval('public.produse_id_seq'::regclass);


--
-- TOC entry 3217 (class 2604 OID 24607)
-- Name: utilizatori id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.utilizatori ALTER COLUMN id SET DEFAULT nextval('public.utilizatori_id_seq'::regclass);


--
-- TOC entry 3392 (class 0 OID 24618)
-- Dependencies: 218
-- Data for Name: accesari; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- TOC entry 3394 (class 0 OID 32796)
-- Dependencies: 220
-- Data for Name: jucarii; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (1, 'minge', 20, 1, '{rosu,verde,galben,roz}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (2, 'ratusca', 5, 0, '{galben,roz}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (3, 'papusa', 47, 5, '{roz,albastru}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (4, 'chitaitoare', 4, 0, '{galben,roz,albastru,rosu,verde}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (5, 'ursulet', 55, 4, '{galben,alb}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (6, 'pistol cu apa', 23, 10, '{negru,roz}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (7, 'disc', 12, 6, '{alb,roz,albastru,galben,verde}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (8, 'coarda', 27, 10, '{negru,galben,albastru}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (9, 'casuta', 120, 11, '{rosu,galben,roz,verde,alb}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (10, 'castel', 255, 12, '{negru,alb}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (11, 'titirez', 18, 7, '{alb,galben,verde,roz,albastru}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (12, 'cuburi', 34, 4, '{albastru,rosu,galben,verde}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (13, 'zar', 2, 6, '{albastru,alb,roz}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (14, 'masinuta', 28, 5, '{albastru,alb,verde}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (15, 'toba', 24, 9, '{verde,galben,alb}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (16, 'plastilina', 17, 8, '{alb,negru,galben,roz,albastru,rosu,verde}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (17, 'margele', 11, 10, '{rosu,roz,alb}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (18, 'minge de plus', 9, 1, '{alb,roz,albastru}', '2022-06-20 12:33:04.045962');
INSERT INTO public.jucarii (id_jucarii, nume, pret, varsta_minima, culori, data_adaugare) VALUES (19, 'zornaitoare', 7, 1, '{rosu,roz,galben,verde}', '2022-06-20 12:33:04.045962');


--
-- TOC entry 3388 (class 0 OID 16518)
-- Dependencies: 214
-- Data for Name: microfoane; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (1, 'AT2035', 'Nimic', 429.00, 2008, 'Condenser', 'Audio-Technica', 'Microfon gaming / podcast', '{40,12,20}', true, 'at2035.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (2, 'ATR2500X-USB', 'Nimic', 549.00, 2019, 'Condenser', 'Audio-Technica', 'Microfon de studio', '{15,5,20}', true, 'atr2500x-usb.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (3, 'BY-M1', 'Nimic', 69.00, 2014, 'Condenser', 'Boya', 'Microfon lavaliera', '{13,5,10}', true, 'by-m1.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (4, 'BY-MM1', 'Microfon Cardioid TRS / TRRS pt Smartphone, Camera, PC BOYA BY-MM1. Include filtru anti-vant.', 139.00, 2014, 'Condenser', 'Boya', 'Microfon lavaliera', '{13,5,10}', true, 'by-mm1.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (5, 'C-1U', 'Behringer C-1U este un microfon condenser de studio cu conexiune prin USB.', 229.00, 2009, 'Condenser', 'Behringer', 'Microfon de studio', '{40,12,20}', true, 'c-1u.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (6, 'ECO-88S', 'Superlux ECO 88S este un microfon de voce, cardioid, cu un design atractiv, constructie solida si ce ofera o frecventa larga de raspuns si o sensibilitate mare.', 48.00, 2014, 'Condenser', 'Superlux', 'Microfon de voce si live', '{20,5,5}', false, 'eco-88s.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (7, 'Lavalier Go', 'Nimic', 299.00, 2020, 'Condenser', 'Rode', 'Microfon lavaliera', '{}', true, 'lavalier-go.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (8, 'Lavalier Go-W', 'Nimic', 325.00, 2020, 'Condenser', 'Rode', 'Microfon lavaliera', '{}', true, 'lavalier-go-w.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (9, 'MKE-200', 'MKE200 este un microfon compact cu condensator pentru camere video sau telefoane, echipat cu un conector de intrare jack de 3,6 mm.', 456.00, 2020, 'Condenser', 'SENNHEISER', 'Microfon pentru camere video', '{7,10,5}', true, 'mke-200.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (10, 'Podcaster', 'Sunet de calitate Broadcast; Capsula dinamica de 28mm;', 898.00, 2018, 'Dinamic', 'Rode', 'Microfon gaming / podcast', '{21,6,6}', false, 'podcaster.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (11, 'PodMic', 'PodMic este un microfon dinamic cu calitate de broadcast optimizat pentru podcast-uri.', 555.00, 2019, 'Dinamic', 'Rode', 'Microfon gaming / podcast', '{}', false, 'podmic.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (12, 'SM-57', 'Microfonul dinamic cardioid SM57 ofera o reproducere curata a instrumentelor amplificate si acustice.', 489.00, 1965, 'Dinamic', 'Shure', 'Microfon de voce si live', '{15,3}', false, 'sm-57.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (13, 'SM-58S', 'Legendarul Shure SM58S este un microfon dinamic de voce construit in special pentru interpretari live in concerte sau dedicat inregistrarilor in studio', 529.00, 1966, 'Dinamic', 'Shure', 'Microfon de voce si live', '{16,5}', false, 'sm58-s.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (14, 'TM58', 'Microfon vocal dinamic, cardioid, cu design si sunet clasic.', 129.00, 2019, 'Dinamic', 'Superlux', 'Microfon de voce si live', '{}', false, 'tm58.jpg', '2022-06-02 20:24:00.76246');
INSERT INTO public.microfoane (id, nume, descriere, pret, an_fabricatie, tip, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (15, 'VideoMic GO', 'Rode VideoMic GO este un microfon compact pentru camere DSLR sau pentru camere foto-video dotate cu mufa jack de 3.5 pentru microfon exterior.', 299.00, 2013, 'Condenser', 'Rode', 'Microfon pentru camere video', '{}', true, 'videomic-go.jpg', '2022-06-02 20:24:00.76246');


--
-- TOC entry 3386 (class 0 OID 16444)
-- Dependencies: 212
-- Data for Name: produse; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.produse (id, nume, descriere, pret, an_fabricatie, tip_produs, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (2, 'SM7B', 'Super Microfon', 1700.00, 2001, 'microfon', 'Shure', 'profesional', '{63,50,189}', false, 'shure-super-55-deluxe.jpg', '2022-06-02 02:13:29.747677');
INSERT INTO public.produse (id, nume, descriere, pret, an_fabricatie, tip_produs, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (3, 'AT2040', 'Nimic', 429.00, 2021, 'microfon', 'Audio-Technica', 'amator', '{40,12,20}', true, 'audio-technica-at2040.jpg', '2022-06-02 02:13:29.747677');
INSERT INTO public.produse (id, nume, descriere, pret, an_fabricatie, tip_produs, producator, categorie, dimensiuni, incl_cablu, imagine, data_adaugare) VALUES (4, 'AT2035', 'Nimic', 429.00, 2008, 'microfon', 'Audio-Technica', 'amator', '{40,12,20}', true, 'audio-technica-at2035.jpg', '2022-06-02 02:13:29.747677');


--
-- TOC entry 3384 (class 0 OID 16396)
-- Dependencies: 210
-- Data for Name: tabel; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.tabel (id, nume, pret) OVERRIDING SYSTEM VALUE VALUES (1, 'mouse
', 200);
INSERT INTO public.tabel (id, nume, pret) OVERRIDING SYSTEM VALUE VALUES (2, 'ceva', 69);
INSERT INTO public.tabel (id, nume, pret) OVERRIDING SYSTEM VALUE VALUES (3, 'zzzz', 50);


--
-- TOC entry 3390 (class 0 OID 24604)
-- Dependencies: 216
-- Data for Name: utilizatori; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.utilizatori (id, username, nume, prenume, parola, rol, email, culoare_chat, data_adaugare, cod, confirmat_mail, tema, ocupatie) VALUES (1, 'prof76804', 'Gogulescu', 'Gogu', '8aa232cc8f4e04aa88b0df334eb72f2ba02aa969b65c4476195204a438f4320306f4b84145fe0e9722298c8ee63e7322d84ef84af652a377c48ee1dd4d813fb0', 'comun', 'profprofprof007@gmail.com', 'black
', '2022-06-16 23:02:44.509465', NULL, false, NULL, NULL);
INSERT INTO public.utilizatori (id, username, nume, prenume, parola, rol, email, culoare_chat, data_adaugare, cod, confirmat_mail, tema, ocupatie) VALUES (2, 'Nicu', 'Sefu', 'Thau', '601a42182c3782edfb09e63cf26078841cf8a7976e6f0d77eb3704da60cc0d7e8eb4c7235078b4eceaa58fbf4498f2528a195d2d8ac1ecf0d2bb8f2ab19b7ac3', 'comun', 'f007@gmail.com', 'black', '2022-06-17 12:27:42.351922', NULL, false, NULL, NULL);
INSERT INTO public.utilizatori (id, username, nume, prenume, parola, rol, email, culoare_chat, data_adaugare, cod, confirmat_mail, tema, ocupatie) VALUES (3, 'prof89615', 'Gogulescu', 'Gogu', '40ab40c8fe4b43b046584138f30c231765e22a26f5f9242b3ce3cb276dbf7ce852a49d7a49ffe70911aee7f3a9a76fae738881fca6d539b9daca84a655922723', 'comun', 'profprofprof007@gmail.com', 'red', '2022-06-26 19:29:13.823557', NULL, false, NULL, NULL);


--
-- TOC entry 3416 (class 0 OID 0)
-- Dependencies: 217
-- Name: accesari_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.accesari_id_seq', 1, false);


--
-- TOC entry 3417 (class 0 OID 0)
-- Dependencies: 219
-- Name: jucarii_id_jucarii_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.jucarii_id_jucarii_seq', 19, true);


--
-- TOC entry 3418 (class 0 OID 0)
-- Dependencies: 213
-- Name: microfoane_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.microfoane_id_seq', 15, true);


--
-- TOC entry 3419 (class 0 OID 0)
-- Dependencies: 211
-- Name: produse_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.produse_id_seq', 4, true);


--
-- TOC entry 3420 (class 0 OID 0)
-- Dependencies: 209
-- Name: tabel_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.tabel_id_seq', 3, true);


--
-- TOC entry 3421 (class 0 OID 0)
-- Dependencies: 215
-- Name: utilizatori_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.utilizatori_id_seq', 4, true);


--
-- TOC entry 3240 (class 2606 OID 24626)
-- Name: accesari accesari_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accesari
    ADD CONSTRAINT accesari_pkey PRIMARY KEY (id);


--
-- TOC entry 3242 (class 2606 OID 32804)
-- Name: jucarii jucarii_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.jucarii
    ADD CONSTRAINT jucarii_pkey PRIMARY KEY (id_jucarii);


--
-- TOC entry 3232 (class 2606 OID 16532)
-- Name: microfoane microfoane_nume_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.microfoane
    ADD CONSTRAINT microfoane_nume_key UNIQUE (nume);


--
-- TOC entry 3234 (class 2606 OID 16530)
-- Name: microfoane microfoane_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.microfoane
    ADD CONSTRAINT microfoane_pkey PRIMARY KEY (id);


--
-- TOC entry 3228 (class 2606 OID 16458)
-- Name: produse produse_nume_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produse
    ADD CONSTRAINT produse_nume_key UNIQUE (nume);


--
-- TOC entry 3230 (class 2606 OID 16456)
-- Name: produse produse_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.produse
    ADD CONSTRAINT produse_pkey PRIMARY KEY (id);


--
-- TOC entry 3226 (class 2606 OID 16400)
-- Name: tabel tabel_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tabel
    ADD CONSTRAINT tabel_pkey PRIMARY KEY (id);


--
-- TOC entry 3236 (class 2606 OID 24614)
-- Name: utilizatori utilizatori_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.utilizatori
    ADD CONSTRAINT utilizatori_pkey PRIMARY KEY (id);


--
-- TOC entry 3238 (class 2606 OID 24616)
-- Name: utilizatori utilizatori_username_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.utilizatori
    ADD CONSTRAINT utilizatori_username_key UNIQUE (username);


--
-- TOC entry 3243 (class 2606 OID 24627)
-- Name: accesari accesari_user_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.accesari
    ADD CONSTRAINT accesari_user_id_fkey FOREIGN KEY (user_id) REFERENCES public.utilizatori(id);


--
-- TOC entry 3400 (class 0 OID 0)
-- Dependencies: 218
-- Name: TABLE accesari; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.accesari TO pepi100;


--
-- TOC entry 3402 (class 0 OID 0)
-- Dependencies: 217
-- Name: SEQUENCE accesari_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.accesari_id_seq TO pepi100;


--
-- TOC entry 3403 (class 0 OID 0)
-- Dependencies: 220
-- Name: TABLE jucarii; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.jucarii TO pepi;
GRANT ALL ON TABLE public.jucarii TO pepi100;


--
-- TOC entry 3405 (class 0 OID 0)
-- Dependencies: 214
-- Name: TABLE microfoane; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.microfoane TO pepi100;


--
-- TOC entry 3407 (class 0 OID 0)
-- Dependencies: 213
-- Name: SEQUENCE microfoane_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.microfoane_id_seq TO pepi100;


--
-- TOC entry 3408 (class 0 OID 0)
-- Dependencies: 212
-- Name: TABLE produse; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.produse TO pepi;
GRANT ALL ON TABLE public.produse TO pepi100;


--
-- TOC entry 3410 (class 0 OID 0)
-- Dependencies: 211
-- Name: SEQUENCE produse_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.produse_id_seq TO pepi;
GRANT ALL ON SEQUENCE public.produse_id_seq TO pepi100;


--
-- TOC entry 3411 (class 0 OID 0)
-- Dependencies: 210
-- Name: TABLE tabel; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.tabel TO pepi;
GRANT ALL ON TABLE public.tabel TO pepi100;


--
-- TOC entry 3412 (class 0 OID 0)
-- Dependencies: 209
-- Name: SEQUENCE tabel_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.tabel_id_seq TO pepi;
GRANT ALL ON SEQUENCE public.tabel_id_seq TO pepi100;


--
-- TOC entry 3413 (class 0 OID 0)
-- Dependencies: 216
-- Name: TABLE utilizatori; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON TABLE public.utilizatori TO pepi100;


--
-- TOC entry 3415 (class 0 OID 0)
-- Dependencies: 215
-- Name: SEQUENCE utilizatori_id_seq; Type: ACL; Schema: public; Owner: postgres
--

GRANT ALL ON SEQUENCE public.utilizatori_id_seq TO pepi100;


-- Completed on 2022-07-04 19:20:28

--
-- PostgreSQL database dump complete
--

