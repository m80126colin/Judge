import Data.Char
import Control.Monad
import Control.Applicative

data Token = Num Int | Symbol Char deriving (Show, Eq)

splitList :: (a -> Bool) -> [a] -> [[a]]
splitList _ [] = []
splitList f (x:xs)
  | f x       = ys  : splitList f zs
  | otherwise = [x] : splitList f xs
  where ys = x : takeWhile f xs
        zs = dropWhile f xs

tokenize :: String -> [Token]
tokenize = map f . splitList isDigit . filter (/= ' ')
  where f a | all isDigit a = Num (read a)
            | otherwise     = Symbol (head a)

data Tree =
    NodePlus  Tree Tree
  | NodeMinus Tree Tree
  | NodeLeaf  Int

parseExpr xs | null xs   = return
             | otherwise = return ()

{-
parseExpr :: Monad m => [Token] -> m Tree
parseExpr [] = Nothing mzero
parseExpr ts = parseTerm ts
-}

{-
eval :: Term -> Int
eval (Mul x y) = (eval x) * (eval y)
eval (Only x)  = eval x
eval (Digit x) = x
eval (Pos x)   = eval x
eval (Neg x)   = - (eval x)
-}