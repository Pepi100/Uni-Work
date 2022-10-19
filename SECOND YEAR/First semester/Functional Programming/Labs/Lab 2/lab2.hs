poly2 :: Double -> Double -> Double -> Double -> Double
poly2 a b c x = a*x^2 + b*x + c


eeny :: Integer -> String
eeny n =    if even n then "eeny"
            else "meeny"

fizzbuzz :: Integer -> String
fizzbuzz n =    if( (mod n 3 == 0) && (mod n 5 == 0) ) then "FizzBuzz"
                else if( mod n 3 == 0 ) then "Fizz"
                    else if( mod n 5 == 0 ) then "Buzz"
                        else ""

{-
fizzbuzz :: Integer -> String
fizzbuzz x
    | x `mod` 5 == 0 && x `mod` 3 == 0 = "FizzBuzz"
    | x `mod` 5 == 0 = "Fizz"
    | x `mod` 3 == 0 = "Buzz"
    | otherwise = ""

-}


fibonacciCazuri :: Integer -> Integer
fibonacciCazuri n
    | n < 2     = n
    | otherwise = fibonacciCazuri (n - 1) + fibonacciCazuri (n - 2)


fibonacciEcuational :: Integer -> Integer
fibonacciEcuational 0 = 0
fibonacciEcuational 1 = 1
fibonacciEcuational n =
    fibonacciEcuational (n - 1) + fibonacciEcuational (n - 2)


tribonacci :: Integer -> Integer
tribonacci 1 = 1
tribonacci 2 = 1
tribonacci 3 = 2
tribonacci n = tribonacci (n-1) + tribonacci (n-2) + tribonacci (n-3)

{-
tribonacci :: Integer -> Integer
tribonacci n
    |   n < 3 = 1
    |   n == 3 = 2
    |   otherwise = tribonacci (n-1) + tribonacci (n-2) + tribonacci (n-3)
-}


binomial :: Integer -> Integer -> Integer
binomial n 0 = 1
binomial 0 k = 0
binomial n k = binomial (n-1) k + binomial (n-1) (k-1)



verifL :: [Int] -> Bool
verifL l =  mod (length l) 2 == 0 



takefinal :: [a] -> Int -> [a]
takefinal l n = drop ( (length l )- n) l 

{-
takefinals :: [Char] -> Int -> [Char]
takefinals l n = drop ( (length l )- n) l 
-}



remove :: [Int] -> Int -> [Int]
remove l n = (take (n-1) l ) ++ (drop (n) l )



-- semiPareRec [0,2,1,7,8,56,17,18] == [0,1,4,28,9]
semiPareRec :: [Int] -> [Int]
semiPareRec [] = []
semiPareRec (h:t)
    | even h    = h `div` 2 : t'
    | otherwise = t'
    where t' = semiPareRec t


myreplicate :: Int -> Int -> [Int]
myreplicate 0 v = []
myreplicate n v =  ( myreplicate (n-1) v ) ++ [v]

sumImp :: [Int] -> Int
sumImp [] = 0
sumImp (h:t)
    | odd h = h + sumImp t
    | otherwise = sumImp t

totalLen :: [String] -> Int
totalLen [] = 0
totalLen (h:t)
    | head h == 'A' = length h + totalLen t
    | otherwise = totalLen t