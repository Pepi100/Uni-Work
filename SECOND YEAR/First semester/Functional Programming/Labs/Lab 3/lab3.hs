import Data.Char

--1
palindrom:: String -> Bool
palindrom x = if x == (reverse x) 
                then True
                else False

vocale :: String -> Int
vocale [] = 0
vocale (h:t)
        | h == 'a' || h == 'e' || h == 'i' || h == 'o' || h == 'u' = (vocale t) + 1
        | otherwise = vocale t

nrVocale :: [String] -> Int
nrVocale [] = 0
nrVocale (h:t)
        | palindrom h = vocale h + nrVocale t
        | otherwise = nrVocale t

--2
adaugaK :: Int -> [Int] -> [Int]
adaugaK x [] = []
adaugaK x (h:t)
        | h `mod` 2 == 0 = [h] ++ [x] ++ (adaugaK x t)
        | otherwise = [h] ++ adaugaK x t

--3
divizori :: Int -> [Int]
divizori n = [x | x <- [1..n], n `mod` x == 0]

--4
listadiv :: [Int] -> [[Int]]
listadiv l = [divizori x | x <- l]

-- 5 b
inInterval:: Int -> Int -> [Int] -> [Int]
inInterval a b l = [x | x <- l, a <= x && x<= b]

-- 5 a
inIntervalRec :: Int -> Int -> [Int] -> [Int]
inIntervalRec a b [] = []
inIntervalRec a b (h:t)
            | a <= h && h <= b = [h] ++ inIntervalRec a b t
            | otherwise = inIntervalRec a b t


-- 6 a
pozitiveRec :: [Int] -> Int
pozitiveRec [] = 0
pozitiveRec (h:t)
        | h > 0 = 1 + pozitiveRec t
        | otherwise = pozitiveRec t

-- 6 b
pozitiveComp :: [Int] -> Int
pozitiveComp l = length [x | x <- l , x > 0]

-- 7 a

piRec :: [Int] -> Int -> [Int]
piRec [] p =[]
piRec (h:t) p 
        | odd h = [p] ++ piRec t (p+1)
        |otherwise = piRec t (p+1)

pozitiiImpareRec :: [Int] -> [Int]
pozitiiImpareRec l = piRec l 0 

--7 b
pozitiiImpareComp :: [Int] -> [Int]
pozitiiImpareComp l =   let 
                            l2 = zip [0..] l
                        in [a | (a,b) <- l2 , odd b]

--8 a

multDigitsRec :: String -> Int
multDigitsRec [] = 1
multDigitsRec (h:t)
        | isDigit h = (digitToInt h) * multDigitsRec t
        | otherwise = multDigitsRec t

--8 b
multDigitsComp :: String -> Int
multDigitsComp l = product [ digitToInt x | x <- l, isDigit x]
