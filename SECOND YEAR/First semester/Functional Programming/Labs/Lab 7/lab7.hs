data Expr = Const Int -- integer constant
          | Expr :+: Expr -- addition
          | Expr :*: Expr -- multiplication
           deriving (Eq)

--1.1
instance Show Expr where
    show(Const n) = show n
    show (expr1 :+: expr2) = "( " ++ show expr1 ++ " + " ++ show expr2 ++ " )"
    show (expr1 :*: expr2) = "( " ++ show expr1 ++ " * " ++ show expr2 ++ " )"

data Operation = Add | Mult deriving (Eq, Show)

data Tree = Lf Int -- leaf
          | Node Operation Tree Tree -- branch
           deriving (Eq, Show)

--1.2
evalExp :: Expr -> Int
evalExp (Const x) = x
evalExp (expr1 :+: expr2) = (evalExp expr1) + (evalExp expr2) 
evalExp (expr1 :*: expr2) = (evalExp expr1) * (evalExp expr2) 

exp1 = ((Const 2 :*: Const 3) :+: (Const 0 :*: Const 5))
exp2 = (Const 2 :*: (Const 3 :+: Const 4))
exp3 = (Const 4 :+: (Const 3 :*: Const 3))
exp4 = (((Const 1 :*: Const 2) :*: (Const 3 :+: Const 1)) :*: Const 2)
test11 = evalExp exp1 == 6
test12 = evalExp exp2 == 14
test13 = evalExp exp3 == 13
test14 = evalExp exp4 == 16

evalArb :: Tree -> Int
evalArb (Lf x) = x
evalArb (Node o t1 t2) 
            | o == Add = (evalArb t1) + (evalArb t2)
            | o == Mult = (evalArb t1) * (evalArb t2)


arb1 = Node Add (Node Mult (Lf 2) (Lf 3)) (Node Mult (Lf 0)(Lf 5))
arb2 = Node Mult (Lf 2) (Node Add (Lf 3)(Lf 4))
arb3 = Node Add (Lf 4) (Node Mult (Lf 3)(Lf 3))
arb4 = Node Mult (Node Mult (Node Mult (Lf 1) (Lf 2)) (Node Add (Lf 3)(Lf 1))) (Lf 2)

test21 = evalArb arb1 == 6
test22 = evalArb arb2 == 14
test23 = evalArb arb3 == 13
test24 = evalArb arb4 == 16


expToArb :: Expr -> Tree
expToArb (Const x) = (Lf x)
expToArb (expr1 :+: expr2) = (Node Add (expToArb expr1 ) (expToArb expr2 ))
expToArb (expr1 :*: expr2) = (Node Mult (expToArb expr1 ) (expToArb expr2 ))



--2.1
class Collection c where
  empty :: c key value
  singleton :: key -> value -> c key value
  insert :: Ord key=> key -> value -> c key value -> c key value
  clookup :: Ord key => key -> c key value -> Maybe value
  delete :: Ord key => key -> c key value -> c key value
  
  keys :: c key value -> [key]
  keys x = [a | (a,b) <- (toList x)] 
  
  values :: c key value -> [value]
  values x = [b | (a,b) <- (toList x)] 
  
  toList :: c key value -> [(key, value)]
  fromList :: Ord key => [(key,value)] -> c key value
  
  fromList [] = empty
  fromList ((x,y):xs)= insert x y t'
                        where t' = fromList xs



newtype PairList k v
  = PairList { getPairList :: [(k, v)] }



--2.2
instance Collection PairList where
    empty :: PairList key value
    empty = PairList []

    singleton :: key -> value -> PairList key value
    singleton k v = PairList [(k,v)]

    insert :: Ord key => key -> value -> PairList key value -> PairList key value
    insert k v (PairList l) = PairList (l ++ [(k,v)] )

    clookup :: Ord key => key -> PairList key value -> Maybe value
    clookup k (PairList []) = Nothing
    clookup k (PairList ((ke,val):t)) 
                    | ke == k = Just val
                    | otherwise = clookup k (PairList t)


    delete :: Ord key => key -> PairList key value -> PairList key value
    delete k (PairList []) = PairList []
    delete k (PairList ((ke,val):t)) 
                    | ke == k = PairList t
                    | otherwise = insert ke val (delete k (PairList t))

    toList :: PairList key value -> [(key, value)]
    toList (PairList l) = l



data SearchTree key value
  = Empty
  | BNode
      (SearchTree key value) -- elemente cu cheia mai mica
      key                    -- cheia elementului
      (Maybe value)          -- valoarea elementului
      (SearchTree key value) -- elemente cu cheia mai mare


instance Collection SearchTree where
  empty = Empty
  singleton k v = BNode Empty k (Just v) Empty

  insert k v (BNode st k1 v1 dr) 
    | k == k1 = BNode st k1 (Just v) dr
    | k < k1 = BNode (insert k v st ) k1 v1 dr
    | k > k1 = BNode st k1 v1 (insert k v dr)  
        
  delete k (BNode st k1 v1 dr)
    | k == k1 = BNode st k1 Nothing dr
    | k < k1 = BNode (delete k st) k1 v1 dr
    | k > k1 = BNode st k1 v1 (delete k dr) 
