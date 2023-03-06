data Punct = Pt [Int]

data Arb = Vid | F Int | N Arb Arb
          deriving Show

class ToFromArb a where
        toArb :: a -> Arb
        fromArb :: Arb -> a
-- Pt [1,2,3]
-- (1, 2, 3)

-- Pt []
-- ()

instance Show Punct where
    show :: Punct -> String
    show(Pt []) = "()"
    show (Pt l) = "(" ++ (tail (foldr (\x y -> "," ++ (show x) ++ y) ")" l)) -- tail scoate , de la inceput


instance ToFromArb Punct where
      toArb :: Punct -> Arb
      toArb (Pt []) = Vid
      toArb (Pt (x:xs)) = N (F x) (toArb (Pt xs))

      fromArb :: Arb -> Punct
      fromArb(Vid) = Pt[]
      fromArb(N (F x) a) = Pt ([x] ++ ( (\(Pt l) -> l) (fromArb a) ))

-- toArb (Pt [1,2,3])
-- N (F 1) (N (F 2) (N (F 3) Vid))
-- fromArb $ N (F 1) (N (F 2) (N (F 3) Vid)) :: Punct
--  (1,2,3)
data Geo a = Square a | Rectangle a a | Circle a
    deriving Show

class GeoOps g where
  perimeter :: (Floating a) => g a -> a
  area :: (Floating a) =>  g a -> a


instance GeoOps Geo where
    perimeter :: Floating a => Geo a -> a
    perimeter (Square a) = 4 * a
    perimeter (Circle a) = 2*a*pi
    perimeter (Rectangle a b) = 2*a + 2*b

    area :: Floating a => Geo a -> a
    area (Square a) = a*a
    area (Circle a) = a*a*pi
    area (Rectangle a b) = a*b

-- ghci> pi
-- 3.141592653589793


instance (Floating a, Eq a) => Eq (Geo a) where
    a == b = (perimeter a) == (perimeter b) 
 

