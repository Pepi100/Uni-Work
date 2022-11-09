
--1
data Fruct
  = Mar String Bool
  | Portocala String Int

ionatanFaraVierme = Mar "Ionatan" False
goldenCuVierme = Mar "Golden Delicious" True
portocalaSicilia10 = Portocala "Sanguinello" 10
listaFructe = [Mar "Ionatan" False,
                Portocala "Sanguinello" 10,
                Portocala "Valencia" 22,
                Mar "Golden Delicious" True,
                Portocala "Sanguinello" 15,
                Portocala "Moro" 12,
                Portocala "Tarocco" 3,
                Portocala "Moro" 12,
                Portocala "Valencia" 2,
                Mar "Golden Delicious" False,
                Mar "Golden" False,
                Mar "Golden" True]

ePortocalaDeSicilia :: Fruct -> Bool
ePortocalaDeSicilia (Mar a b) = False
ePortocalaDeSicilia (Portocala a b) 
                        | a == "Moro" || a == "Tarocco" || a == "Sanguinello" = True
                        | otherwise = False


test_ePortocalaDeSicilia1 =
    ePortocalaDeSicilia (Portocala "Moro" 12) == True
test_ePortocalaDeSicilia2 =
    ePortocalaDeSicilia (Mar "Ionatan" True) == False


getFelii :: Fruct -> Int
getFelii (Portocala a b) = b
getFelii (Mar b c) = 0

nrFeliiSicilia :: [Fruct] -> Int
nrFeliiSicilia  [] = 0
nrFeliiSicilia ( h :t)
                    | ePortocalaDeSicilia h == True = getFelii h + nrFeliiSicilia t
                    | otherwise = nrFeliiSicilia t

test_nrFeliiSicilia = nrFeliiSicilia listaFructe == 52

nrMereViermi :: [Fruct] -> Int
nrMereViermi [] = 0
nrMereViermi ((Portocala _ _ ):t ) = nrMereViermi t
nrMereViermi ( (Mar a b): t ) 
                | b = nrMereViermi t + 1
                | otherwise = nrMereViermi t

test_nrMereViermi = nrMereViermi listaFructe == 2


--2
type NumeA = String
type Rasa = String
data Animal = Pisica NumeA | Caine NumeA Rasa
    deriving Show

vorbeste :: Animal -> String
vorbeste (Pisica a) = "Meow!"
vorbeste (Caine a b) = "Woof!" 

rasa :: Animal -> Maybe String
rasa (Caine a b) =  Just b
rasa (Pisica a) = Nothing 


--3

data Linie = L [Int]
   deriving Show

data Matrice = M [Linie]
   deriving Show


verifica :: Matrice -> Int -> Bool
verifica (M l) n = foldl (&&) True (map (\(L p) -> sum p == n)  l)      


test_veri1 = verifica (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 10 == False
test_verif2 = verifica (M[L[2,20,3], L[4,21], L[2,3,6,8,6], L[8,5,3,9]]) 25 == True


--doarPozitive (L a) = foldl (&&) True  (map (\x -> x >= 0) a)

doarPozN :: Matrice -> Int -> Bool
doarPozN (M l) n = foldl (&&) True (map (\(L a) -> foldl (&&) True  (map (\x -> x >= 0) a))  (filter (\(L p) -> length p == n)  l) )

testPoz1 = doarPozN (M [L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == True
testPoz2 = doarPozN (M [L[1,2,-3], L[4,5], L[2,3,6,8], L[8,5,3]]) 3 == False


rasp (h:t) =  foldl (&&) True ( map( == h) (t)) 

corect2 :: Matrice -> Bool
corect2 (M m) =   rasp ( map (\(L l) -> length l)  m  ) 

corect :: Matrice -> Bool
corect (M [] ) = True
corect (M [a] ) = True
corect (M ((L h):( L h2) :t)) 
        | length t == 0 = (length h == length h2)
        | length h == length h2 = True && corect (M ( [ (L h) ] ++ t ))
        | otherwise = False


testcorect1 = corect (M[L[1,2,3], L[4,5], L[2,3,6,8], L[8,5,3]]) == False
testcorect2 = corect (M[L[1,2,3], L[4,5,8], L[3,6,8], L[8,5,3]]) == True
