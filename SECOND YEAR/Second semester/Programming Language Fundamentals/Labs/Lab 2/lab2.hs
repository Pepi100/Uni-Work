
import Control.Applicative
import Data.Char
-- import Distribution.Simple.Program.GHC (GhcOptions(ghcOptInstantiatedWith, ghcOptDylibName))
import Data.List

newtype Parser a = Parser { apply :: String -> [(a, String)] }

satisfy :: (Char -> Bool) -> Parser Char
satisfy p = Parser go
  where
    go [] = []   -- imposibil de parsat șirul vid
    go (c:input)
      | p c = [(c, input)]   -- dacă predicatul ține, întoarce c și restul șirului de intrare
      | otherwise = []       -- în caz contrar, imposibil de parsat


--- | Acceptă orice caracter
anychar :: Parser Char
-- anychar = Parser go2
--     where
--     go2 [] = []
--     go2 (h:t) = [(h,t)]

anychar = satisfy (\x -> True)

--- | acceptă doar caracterul dat ca argument
char :: Char -> Parser Char
-- char chr = Parser go
--   where
--     go [] = []
--     go (h:t)
--       | chr == h = [(h,t)]
--       | otherwise = []

char chr= satisfy (\x -> x == chr)

--- | acceptă o cifră
digit :: Parser Char
-- digit = Parser go
--   where
--     go [] = []
--     go (h:t)
--       | isDigit h = [(h,t)]
--       | otherwise = []
digit = satisfy (\x -> isDigit x)


--- | acceptă un spațiu (sau tab, sau sfârșit de linie -- vedeți funcția din Data.Char )
space :: Parser Char
space = satisfy (\x -> isSpace x)
-- 

--- | succes doar dacă am șirul de intrare este vid 
endOfInput :: Parser ()
endOfInput  = Parser go
  where
    go "" = [((), "")]
    go _ = []

instance Functor Parser where
    fmap f pa = Parser (\input -> [(f a, rest) | (a, rest) <- apply pa input])

instance Applicative Parser where
    pure a = Parser (\input -> [(a, input)])
    pf <*> pa = Parser (\input -> [(f a, resta) | (f, restf) <- apply pf input, (a, resta) <- apply pa restf])


parseCifra :: Parser Int
parseCifra = digitToInt <$> digit
douaCifre :: Num a => a -> a -> a
douaCifre c1 c2 = 10 * c1 + c2

parse :: Parser a -> String -> Either String a
parse p str = case apply p str of
  [(h,[])] -> Right h
  [(_, rest)] -> Left ("Sirul nu a fost consumat")
  _ -> Left ("Nu s-a putut parsa") 

instance Monad Parser where
    pa >>= k = Parser (\input -> [(b, restb) | (a, resta) <- apply pa input, (b, restb) <- apply (k a) resta])


cifraIntreParanteze :: Parser Int
cifraIntreParanteze = do
  char '('
  d <- digit
  char ')'
  return (digitToInt d)


cifraSemn :: Parser Int
cifraSemn = do
  semn <- char '-' <|> char '+'
  d <- digit
  if semn == '-' then
    return  ( (-1) * digitToInt d )
    else 
      return (digitToInt d)

string :: String -> Parser String
string str = Parser go
  where
    go [] = []   -- imposibil de parsat șirul vid
    go (input)
      | isPrefixOf str input = [(str, input)]   
      | otherwise = [] 

instance Alternative Parser where
    empty = Parser (const [])
    p <|> p' = Parser (\input -> apply p input ++ apply p' input)

naiveNatural :: Parser Int
naiveNatural = undefined

-- | Elimină zero sau mai multe apariții ale lui `space`
whiteSpace :: Parser ()
whiteSpace = do
  many space
  return ()

-- | parses a natural number (one or more digits)
nat :: Parser Int
nat = do
  many digit
  return (int)

-- | aplică un parser, și elimină spațiile de după
lexeme :: Parser a -> Parser a
lexeme = undefined

-- | parses a natural number and skips the space after it
natural :: Parser Int
natural = undefined

-- | Parses the string and skips whiteSpace after it
symbol :: String -> Parser String
symbol = undefined

-- | Parses the string, skips whiteSpace, returns unit
reserved :: String -> Parser ()
reserved = undefined

-- | parsează virgulă, eliminând spațiile de după
comma :: Parser ()
comma = undefined

-- | parsează argumentul intre paranteze rotunde
--   elimină spațiile de după paranteze
parens :: Parser a -> Parser a
parens = undefined

-- | parsează argumentul intre paranteze pătrate
--   elimină spațiile de după paranteze
brackets :: Parser a -> Parser a
brackets = undefined

-- | una sau mai multe instanțe, separate de virgulă,
--   cu eliminarea spațiilor de după fiecare virgulă
--   intoarce lista obiectelor parsate
commaSep1 :: Parser a -> Parser [a]
commaSep1 = undefined

-- | zero sau mai multe instanțe, separate de virgulă,
--   cu eliminarea spațiilor de după fiecare virgulă
--   intoarce lista obiectelor parsate
commaSep :: Parser a -> Parser [a]
commaSep = undefined

-- | date fiind parsere pentru prima literă si pentru felul literelor următoare
--   scrieți un parser pentru un identificator
ident :: Parser Char -> Parser Char -> Parser String
ident identStart identLetter = undefined

-- | ca mai sus, dar elimină spatiile de după
identifier :: Parser Char -> Parser Char -> Parser String
identifier start letter = lexeme (ident start letter)

