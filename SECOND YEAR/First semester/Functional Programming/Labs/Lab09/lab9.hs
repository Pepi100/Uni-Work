import Data.List (nub)
import Data.Maybe (fromJust)


type Nume = String
data Prop
  = Var Nume
  | F
  | T
  | Not Prop
  | Prop :|: Prop
  | Prop :&: Prop
  | Prop :->: Prop
  | Prop :<->: Prop
  deriving (Eq, Read)
infixr 2 :|:
infixr 3 :&:


p1 :: Prop
p1 = (Var "P" :|: Var "Q") :&: (Var "P" :&: Var "Q")

p2 :: Prop
p2 = (Var "P" :|: Var "Q") :&: ( Not (Var "P") :&: Not (Var "Q"))

p3 :: Prop
p3 = (Var "P" :&: (Var "Q" :|: Var "R")) :&: ( Not (Var "P") :|: Not (Var "Q")) :&: ( Not (Var "P") :|: Not (Var "R"))


instance Show Prop where
  show :: Prop -> String
  show (Var nume) = nume
  show (Not x) = "(~" ++ show x ++ ")"
  show (x :|: y) = "(" ++ show x ++ "|" ++ show y ++ ")"
  show (x :&: y) = "(" ++ show x ++ "&" ++ show y ++ ")"
 
test_ShowProp :: Bool
test_ShowProp =
    show (Not (Var "P") :&: Var "Q") == "((~P)&Q)"

type Env = [(Nume, Bool)]

impureLookup :: Eq a => a -> [(a,b)] -> b
impureLookup a = fromJust . lookup a

eval :: Prop -> Env -> Bool
eval F _ = False
eval T _ = True
eval (Var nume) env = impureLookup nume env 
eval (x :|: y) env = eval x env || eval y env
eval (x :&: y) env = eval x env && eval y env
eval (Not x) env = not (eval x env)
 
test_eval = eval  (Var "P" :|: Var "Q") [("P", True), ("Q", False)] == True

variabile :: Prop -> [Nume]
variabile T = []
variabile F = []
variabile (Var nume) = [nume]
variabile (Not x) = variabile x
variabile (x :|: y) = (nub ((variabile x) ++ (variabile y)))
variabile (x :&: y) = (nub ((variabile x) ++ (variabile y)))
 
test_variabile =
  variabile (Not (Var "P") :&: Var "Q") == ["P", "Q"]

envs :: [Nume] -> [Env]
envs [] = [[]]
envs (h:t) = [[(h, False)] ++ rest | rest <- envs t ] ++ [[(h, True)]  ++ rest | rest <- envs t ]
 
test_envs = 
    envs ["P", "Q"]
    ==
    [ [ ("P",False)
      , ("Q",False)
      ]
    , [ ("P",False)
      , ("Q",True)
      ]
    , [ ("P",True)
      , ("Q",False)
      ]
    , [ ("P",True)
      , ("Q",True)
      ]
    ]

satisfiabila :: Prop -> Bool
satisfiabila x= foldr (||) False [ (eval x op) | op <- ( envs (variabile x) )]
 
test_satisfiabila1 = satisfiabila (Not (Var "P") :&: Var "Q") == True
test_satisfiabila2 = satisfiabila (Not (Var "P") :&: Var "P") == False

valida :: Prop -> Bool
valida x = foldr (&&) True [ (eval x op) | op <- ( envs (variabile x) )]

test_valida1 = valida (Not (Var "P") :&: Var "Q") == False
test_valida2 = valida (Not (Var "P") :|: Var "P") == True


echivalenta :: Prop -> Prop -> Bool
echivalenta  x y= foldr (&&) True [ (eval x op) == (eval y op2) | op <- ( envs (variabile x) ), op2 <- ( envs (variabile y) )]
 
test_echivalenta1 =
  True
  ==
  (Var "P" :&: Var "Q") `echivalenta` (Not (Not (Var "P") :|: Not (Var "Q")))
test_echivalenta2 =
  False
  ==
  (Var "P") `echivalenta` (Var "Q")
test_echivalenta3 =
  True
  ==
  (Var "R" :|: Not (Var "R")) `echivalenta` (Var "Q" :|: Not (Var "Q"))

