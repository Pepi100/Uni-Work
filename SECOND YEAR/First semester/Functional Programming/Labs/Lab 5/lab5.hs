import Data.Char

--1
sumPatrateImpare :: [Int] -> Int
sumPatrateImpare  l = foldr (+) 0 (map(\x -> x*x) (filter odd l))

--2

checkTrue:: [Bool] -> Bool
checkTrue l = foldr (&&) True l

--3
allVerifies :: (Int -> Bool) -> [Int] -> Bool
allVerifies o l = foldr ( \x y-> y && (o x)) True l

--4
anyVerifies :: (Int -> Bool) -> [Int] -> Bool
anyVerifies o l = foldr (\x y-> y || (o x)) False l

--5

mapFoldr :: (a->b) -> [a] ->[b]
mapFoldr o l = foldr (\x y -> [(o x)] ++ y ) [] l

filterFoldr :: (a->Bool) -> [a] ->[a]
filterFoldr o l = foldr (\x y -> if o x then   x : y else y) [] l

--6

listToInt :: [Integer] -> Integer
listToInt l = foldl (\x y -> x*10 +y) 0 l

listToIntr :: [Integer] -> Integer
listToIntr l = foldr (\x y -> y*10 +x) 0 l

--7
rmChar :: Char -> String -> String
rmChar c s= filter (\x -> x /= c) s 

-- 7b

rmCharsRec :: String -> String -> String
rmCharsRec [] l = l
rmCharsRec (h:t) l=  rmCharsRec t (rmChar h l)

--7c 
rmCharsFold :: String -> String -> String
rmCharsFold s l = foldr (rmChar) l s