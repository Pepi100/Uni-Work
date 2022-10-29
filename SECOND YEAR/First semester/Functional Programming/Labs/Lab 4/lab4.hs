import Data.Char

factori :: Int -> [Int]
factori n = [x | x <- [1..n],  rem n x == 0 ]

prim :: Int -> Bool
prim n
    | length (factori n ) == 2 = True
    | otherwise = False

numerePrime:: Int -> [Int]
numerePrime n = [x | x <- [2..n], prim x == True]

myzip3 :: [Int] -> [Int] -> [Int] -> [(Int, Int, Int)]
myzip3 a b [] = []
myzip3 a [] b = []
myzip3 [] a b = []
myzip3 (h1:t1) (h2:t2) (h3:t3) = [(h1,h2,h3)] ++ myzip3 t1 t2 t3  


firstEl:: [(a, b)] -> [a]
firstEl l = map (\(a,b) -> a ) l


sumList :: [[Int]] -> [Int]
sumList l = map sum l

--7
prehelp :: Int -> Int
prehelp n 
        | rem n 2 == 0 = div n 2
        | otherwise = n*2

pre12 :: [Int] -> [Int]
pre12 l = map prehelp l

--8
strchr :: Char -> [String] -> [String]
strchr c l = filter (elem c) l

--9
patrateImp :: [Int] -> [Int]
patrateImp l = map (\x -> x * x) (filter odd l)

--10

patratePozImp :: [Int] -> [Int]
patratePozImp l = map (\(a,x) -> x * x) (filter (\(a,x) -> odd a)(zip [1..(length l)] l))

--11
numaiVocale :: [String] -> [String]
numaiVocale l = map ( filter ( \x -> toLower x == 'a' || toLower x == 'e' || toLower x == 'o' || toLower x == 'i' || toLower x == 'u'  ) ) l


--12
mymap :: (a -> b) -> [a] -> [b]
mymap f [] = []
mymap f (h:t) = [f h] ++ mymap f t 

myfilter:: (a-> Bool) -> [a] -> [a]
myfilter f [] = []
myfilter f (h:t) 
        | f h == True = [h] ++ myfilter f t
        | otherwise = myfilter f t
