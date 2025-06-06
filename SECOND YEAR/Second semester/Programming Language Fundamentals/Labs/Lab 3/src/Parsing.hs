
module Parsing where

import Exp
import Text.ParserCombinators.Parsec
import Text.ParserCombinators.Parsec.Language
    ( haskellStyle, LanguageDef )
import Text.ParserCombinators.Parsec.Token
import Control.Applicative (some)

miniHaskellDef :: LanguageDef st
miniHaskellDef = haskellStyle{
    reservedNames = ["let", "in", "letrec"],
    reservedOpNames = ["\\", "->", "=", "[", "]" ]

}

miniHs :: TokenParser st
miniHs = makeTokenParser miniHaskellDef

testParse :: Parser a -> String -> a
testParse p s
  = case parse p "<input>" s of
      Left err -> error (show err)
      Right a -> a

var :: Parser Var
var = do
    x <- identifier miniHs
        <|> operator miniHs
    return $ Var x
-- >>>  testParse var "b is a var"
-- Var {getVar = "b"}

varExp :: Parser ComplexExp
varExp = do
    v <- var
    return $ CX v
-- >>> testParse varExp "b is a var"
-- CX (Var {getVar = "b"})

lambdaExp :: Parser ComplexExp
lambdaExp =do 
    reservedOp miniHs "\\"
    v <- var
    reservedOp miniHs "->"
    e <- expr
    return $ CLam v e

-- >>> testParse lambdaExp "\\x -> x"
-- CLam (Var {getVar = "x"}) (CX (Var {getVar = "x"}))

letExp :: Parser ComplexExp
letExp = do 
    reservedOp miniHs "let"
    v <- var
    reservedOp miniHs ":="
    e <- expr
    reservedOp miniHs "in"
    z <- expr
    return $ Let v e z
-- >>> testParse letExp "let x := y in z"
-- Let (Var {getVar = "x"}) (CX (Var {getVar = "y"})) (CX (Var {getVar = "z"}))

letrecExp :: Parser ComplexExp
letrecExp = do
    reservedOp miniHs "letrec"
    v <- var
    reservedOp miniHs ":="
    e <- expr
    reservedOp miniHs "in"
    z <- expr
    return $ LetRec v e z
-- >>> testParse letrecExp "letrec x := y in z"
-- LetRec (Var {getVar = "x"}) (CX (Var {getVar = "y"})) (CX (Var {getVar = "z"}))

listExp :: Parser ComplexExp
listExp = do
    _ <- char '['
    exps <- sepBy (identifier miniHs) (char ',')
    _ <- char ']'
    return $ List (map CX (map Var exps)) 
-- >>> testParse listExp "[a,b,c]"
-- List [CX (Var {getVar = "a"}),CX (Var {getVar = "b"}),CX (Var {getVar = "c"})]

natExp :: Parser ComplexExp
natExp = do
    n <- natural miniHs 
    _ <- anyChar
    return $ Nat (fromInteger n)
-- >>> testParse natExp "223 a"
-- Nat 223

parenExp :: Parser ComplexExp
parenExp = undefined
-- >>> testParse parenExp "(a)"
-- CX (Var {getVar = "a"})

basicExp :: Parser ComplexExp
basicExp = undefined
-- >>> testParse basicExp "[a,b,c]"
-- List [CX (Var {getVar = "a"}),CX (Var {getVar = "b"}),CX (Var {getVar = "c"})]

expr :: Parser ComplexExp
expr = varExp
-- >>> testParse expr "\\x -> [x,y,z]"
-- CLam (Var {getVar = "x"}) (List [CX (Var {getVar = "x"}),CX (Var {getVar = "y"}),CX (Var {getVar = "z"})])

exprParser :: Parser ComplexExp
exprParser = whiteSpace miniHs *> expr <* eof
-- >>> testParse exprParser "let x := 28 in \\y -> + x y"
-- Let (Var {getVar = "x"}) (Nat 28) (CLam (Var {getVar = "y"}) (CApp (CApp (CX (Var {getVar = "+"})) (CX (Var {getVar = "x"}))) (CX (Var {getVar = "y"}))))

