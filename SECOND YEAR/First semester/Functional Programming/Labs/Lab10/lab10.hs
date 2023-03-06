{-
class Functor f where
fmap : : ( a -> b ) -> f a -> f b
-}
newtype Identity a = Identity a

instance Functor Identity where
    fmap :: (a -> b) -> Identity a -> Identity b
    fmap f (Identity x) = (Identity (f x))

data Pair a = Pair a a

instance Functor Pair where
    fmap :: (a -> b) -> Pair a -> Pair b
    fmap f (Pair x y) = Pair (f x) (f y)

data Constant a b = Constant b

instance Functor (Constant a )where
    fmap f (Constant b) = Constant (f b)

-- il pot mapa doar pe cel mai din dreapta, din stanga egalului
data Two a b = Two a b
instance Functor (Two a )where
    fmap :: (a2 -> b) -> Two a1 a2 -> Two a1 b
    fmap f (Two a b) = Two a (f b)


data Three a b c = Three a b c

instance Functor (Three a b ) where
    fmap f (Three a b c) = Three a b (f c)

data Three' a b = Three' a b b

instance Functor (Three' a ) where
    fmap f (Three' a b c) = Three' a (f b) (f c)


data Four a b c d = Four a b c d

instance Functor (Four a b c) where
    fmap f (Four a b c d) = (Four a b c (f d))


data Four'' a b = Four'' a a a b

instance Functor (Four'' a ) where
    fmap f (Four'' a b c d) = (Four a b c (f b))

data Quant a b = Finance | Desk a | Bloor b

instance Functor (Quant a) where
    fmap f Finance = Finance
    fmap f (Desk x) = (Desk x)
    fmap f (Bloor y) = (Bloor (f y))


data LiftItOut f a = LiftItOut (f a)




data Parappa f g a = DaWrappa (f a) (g a)

data IgnoreOne f g a b = IgnoringSomething (f a) (g b)

data Notorious g o a t = Notorious (g o) (g a) (g t)

data GoatLord a = NoGoat | OneGoat a | MoreGoats (GoatLord a) (GoatLord a) (GoatLord a)

instance Functor GoatLord where
    fmap :: (a -> b) -> GoatLord a -> GoatLord b
    fmap f NoGoat = NoGoat
    fmap f (OneGoat a) = OneGoat (f a)
    fmap func (MoreGoats x y z) = (MoreGoats (fmap func x) (fmap func y) (fmap func z))


data TalkToMe a = Halt | Print String a | Read (String -> a)

instance Functor TalkToMe where
    fmap :: (a -> b) -> TalkToMe a -> TalkToMe b
    fmap f Halt = Halt
    fmap f (Print s a) = Print s (f a)
    fmap f (Read function) =  Read (f . function)
