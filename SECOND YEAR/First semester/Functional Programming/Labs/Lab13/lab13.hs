
{- Monada Maybe este definita in GHC.Base 

instance Monad Maybe where
  return = Just
  Just va  >>= k   = k va
  Nothing >>= _   = Nothing


instance Applicative Maybe where
  pure = return
  mf <*> ma = do
    f <- mf
    va <- ma
    return (f va)       

instance Functor Maybe where              
  fmap f ma = pure f <*> ma   
-}


-- Daca citesti asta si vrei sa intelegi ce se intampla, watch this: 
-- https://www.youtube.com/watch?v=t1e8gqXLbsU
pos :: Int -> Bool
pos  x = if (x>=0) then True else False



fct :: Maybe Int ->  Maybe Bool
-- daca mx exista il pune in functia lambda 
fct  mx =  mx  >>= (\x -> Just (pos x))


fct2 :: Maybe Int -> Maybe Bool
fct2 mx = do
    x <- mx
    return (pos x)

addM :: Maybe Int -> Maybe Int -> Maybe Int
addM mx my = do
  x <- mx
  y <- my
  return (x+y)

addMSabloane :: Maybe Int -> Maybe Int -> Maybe Int
addMSabloane Nothing _ = Nothing
addMSabloane _ Nothing = Nothing
addMSabloane (Just a) (Just b) = Just (a + b)



cartesian_product :: Monad m => m a -> m b -> m (a, b)
--cartesian_product xs ys = xs >>= ( \x -> (ys >>= \y-> return (x,y)))
cartesian_product xs xy = do
  x <- xs
  y <- xy
  return (x,y)


prod1 f xs ys = [f x y | x <- xs, y<-ys]
prod :: Monad m => (t1 -> t2 -> b) -> m t1 -> m t2 -> m b
prod f xy ys = do
    x <- xy
    y <- ys
    return (f x y)

myGetLine :: IO String
myGetLine = getChar >>= \x ->
      if x == '\n' then
          return []
      else
          myGetLine >>= \xs -> return (x:xs)

myGetLine2 = do
  x <- getChar
  if x == '\n' then
    return []
  else do
    s <- myGetLine2
    return (x:s)

--prelNo noin =  sqrt noin
prelNo noin = do
  n <- noin
  return (sqrt n) 

ioNumber = do
     noin  <- readLn :: IO Float
     putStrLn $ "Intrare\n" ++ (show noin)
     let  noout = prelNo noin
     putStrLn $ "Iesire"
     print noout

data Person = Person { name :: String, age :: Int }

showPersonN :: Person -> String
showPersonN = undefined
showPersonA :: Person -> String
showPersonA = undefined

{-
showPersonN $ Person "ada" 20
"NAME: ada"
showPersonA $ Person "ada" 20
"AGE: 20"
-}

showPerson :: Person -> String
showPerson = undefined 

{-
showPerson $ Person "ada" 20
"(NAME: ada, AGE: 20)"
-}


newtype Reader env a = Reader { runReader :: env -> a }


instance Monad (Reader env) where
  return x = Reader (\_ -> x)
  ma >>= k = Reader f
    where f env = let a = runReader ma env
                  in  runReader (k a) env



instance Applicative (Reader env) where
  pure = return
  mf <*> ma = do
    f <- mf
    a <- ma
    return (f a)       

instance Functor (Reader env) where              
  fmap f ma = pure f <*> ma    

mshowPersonN ::  Reader Person String
mshowPersonN = undefined
mshowPersonA ::  Reader Person String
mshowPersonA = undefined 
mshowPerson ::  Reader Person String
mshowPerson = undefined 
{-
runReader mshowPersonN  $ Person "ada" 20
"NAME:ada"
runReader mshowPersonA  $ Person "ada" 20
"AGE:20"
runReader mshowPerson  $ Person "ada" 20
"(NAME:ada,AGE:20)"
-}