import Data.List

myInt = 5555555555555555555555555555555555555555555555555555555555555555555555555555555555555

double :: Integer -> Integer
double x = x+x

triple :: Integer -> Integer
triple x = x*3


maxim :: Integer -> Integer -> Integer
maxim x y =    if (x > y)
                    then x
               else y

max3 x y z = let
             u = maxim x y
             in (maxim  u z)

maxim3 a b c = if(a>b)
                    then if (a>c)
                              then a
                         else c
               else if(b>c)
                         then b
                    else c

maxim4 a b c d = let
                    ab = maxim a b
                    cd = maxim c d
                 in maxim ab cd 
               
testare a b c d = let 
                    max = maxim4 a b c d
               in max >= a && max >= b && max >= c && max >= d

patrate :: Integer -> Integer -> Integer
patrate a b = a*a + b*b

paritate :: Integer -> [Char]
paritate a = if( odd a)
                    then "impar"
          else "par"


factorial a =  if(a==0)
                    then 1
               else let
                         ac = a-1
                         u = factorial ac
                    in u * a

maiMare2 a b = let 
               dublu = 2*b
               in a>dublu
               

               
