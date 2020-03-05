import Data.Char
import Text.Regex.Base
import Text.Regex.Posix
import Control.Monad
import Control.Applicative
import Text.Printf

generate :: (Num a, Enum a) => a -> [a]
generate n = [1 .. n]

minus :: Num a => a -> a -> a
minus = flip (-)

{-
  generating function
-}

type GenFunc = [Double]

gfDice :: Int -> GenFunc
gfDice n = 0 : replicate n (1 / fromIntegral n)

gfZero :: Int -> GenFunc
gfZero n = replicate (n + 1) 0

gfNeg :: GenFunc -> GenFunc
gfNeg = map negate

gfPad :: Int -> Int -> GenFunc -> GenFunc
gfPad sft len xs = concat [replicate left 0, take middle xs, replicate right 0]
  where
    left   = sft
    middle = len - sft
    right  = len - sft - length xs

gfSum :: [GenFunc] -> GenFunc
gfSum xss = foldr1 (zipWith (+)) (gfPad 0 len <$> xss)
  where len = foldr1 max (length <$> xss)

gfAdd :: GenFunc -> GenFunc -> GenFunc
gfAdd xs ys = gfSum [xs, ys]

gfMul :: GenFunc -> GenFunc -> GenFunc
gfMul xs ys = foldr1 (zipWith (+)) . map f . zip [0..] $ ys
  where
    len      = sum (minus 1 . length <$> [xs, ys]) + 1
    f (x, d) = gfPad x len (map (* d) xs)

gfProd :: [GenFunc] -> GenFunc
gfProd = foldr1 gfMul

gfExp :: Int -> GenFunc -> GenFunc
gfExp n = gfProd . replicate n

{-
  probability table
-}

table :: [Int]
table = [0 .. 20]

gfTable :: [[GenFunc]]
gfTable = map (\f -> f <$> gfDice <$> table) (gfExp <$> table)

{-
  solution
-}

pat :: String
pat = "([0-9]+)d([0-9]+)(\\+[0-9]+|\\-[0-9]+)?"

pattern :: String -> [Int]
pattern = map f . tail . getAllTextSubmatches . (=~ pat)
  where
    f x | x == ""       = 0
        | head x == '+' = read $ tail x
        | otherwise     = read x

solve :: (Int, [String]) -> Double
solve (h, ss) = foldr1 max $ map (possible . pattern) ss
  where possible [x, y, z] = sum $ drop (h - z) (gfTable !! x !! y)

{-
  IO
-}

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO (Int, [String])
getCase =
  getLine >>= \ints ->
  getLine >>= \strs ->
    return (read . head . words $ ints, words $ strs)

printCase :: (Int, Double) -> IO ()
printCase (n,d) = putStrLn . concat $ ["Case #", show n, ": ", printf "%.6f" d]

main :: IO ()
main = getInt >>= \n -> replicateM n getCase
              >>= mapM_ printCase . zip (generate n) . map solve