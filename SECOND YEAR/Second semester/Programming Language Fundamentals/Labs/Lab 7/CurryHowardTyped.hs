 

data False                                        -- empty type

data True = True                                  -- unit type

data And a b = And { proj1 :: a, proj2 :: b }     -- product

data Or a b                                       -- sum
  = Left a
  | Right b

type Not a = a -> False
type Iff a b = And (a -> b) (b -> a)

-- Natural deduction introduction and elimination rules

trueIntro :: True                                   -- true introduction
trueIntro = True

falseElim :: False -> b                             -- false elimination
falseElim x = case x of

implIntro :: (a -> b) -> (a -> b)                   -- implication introduction
implIntro f = f 

implElim :: (a -> b) -> a -> b                      -- implication elimination
implElim f x = f x  

andIntro :: a -> b -> And a b                       -- and introduction
andIntro x y = And { proj1 = x, proj2 = y }

andElimL :: And a b -> a                            -- and elimination 1
andElimL (And x _) = x

andElimR :: And a b -> b                            -- and elimination 2
andElimR (And _ x) = x

orIntroL :: a -> Or a b                             -- or introduction 1
orIntroL x = Left x

orIntroR :: b -> Or a b                             -- or introduction 2
orIntroL x = Right x

orElim :: Or a b -> (a -> c) -> (b -> c) -> c       -- or elimination
orElim = undefined

notElim :: Not p -> p -> c                          -- not elimination 
notElim = undefined

notIntro :: (forall p. a -> p) -> Not a             -- not introduction
notIntro _ = undefined

iffIntro :: (a -> b) -> (b -> a) -> Iff a b
iffIntro x y = And { proj1 = x, proj2 = y }

iffElimL :: Iff a b -> a -> b
iffElimL (And f _) x = f x

iffElimR :: Iff a b -> b -> a
iffElimR (And _ f) x = f x


-- Hilbert-style axiomatization for intuitionistic propositional logic
ax1 :: a -> b -> a
ax1 x _ = x


ax2 :: (a -> b) -> (a -> (b -> c)) -> a -> c
ax2 f g x = g x (f x)

ax3 :: a -> b -> And a b
ax3 x y = And { proj1 = x, proj2 = y }

ax4 :: And a b -> a
ax4 (And x _) = x

ax5 :: And a b -> b
ax5 (And _ y) = y

ax6 :: a -> Or a b
ax6 x = Left x

ax7 :: b -> Or a b
ax7 y = Right y

ax8 :: (a -> c) -> (b -> c) -> Or a b -> c
ax8 f g (Left x) = f x
ax8 f g (Right y) = g y

ax9 :: (a -> b) -> (a -> Not b) -> Not a
ax9 f g x = g x (f x)

ax10 :: Not a -> a -> b
ax10 f x = absurd (f x)

modusPonens :: (a -> b) -> a -> b
modusPonens f x = f x


-- Several tautologies

pNPFalse :: p -> Not p -> False
pNPFalse x f = f x

deMorgan1 :: And (Not p) (Not q) -> Not (Or p q)
deMorgan1 (And np nq) = \case
  Left p -> np p
  Right q -> nq q

deMorgan2 :: Not (Or p q) -> And (Not p) (Not q)
deMorgan2 f = And (\p -> f (Left p)) (\q -> f (Right q))

deMorgan3 :: Or (Not p) (Not q) -> Not (And p q)
deMorgan3 = \case
  Left np -> \case
    And p _ -> np p
  Right nq -> \case
    And _ q -> nq q


type DeMorgan4 = forall p q. Not (And p q) -> Or (Not p) (Not q)

-- Classical axioms

type ExcludedMiddle = forall a. Or a (Not a)
type DoubleNegation = forall a. Not (Not a) -> a
type PeirceLaw = forall p q. ((p -> q) -> p) -> p

excludedMiddleImplDoubleNeg :: ExcludedMiddle -> DoubleNegation
excludedMiddleImplDoubleNeg em f = em >>= either id (f . const)

doubleNegImplExcludedMiddle :: DoubleNegation -> ExcludedMiddle
doubleNegImplExcludedMiddle dn = dn (const False)

classicDeMorgan4 :: ExcludedMiddle -> DeMorgan4
classicDeMorgan4 em f = em >>= either (Right . const False) (Left . const False)


