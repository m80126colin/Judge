import Data.Char
import Control.Monad

sumOfDigit :: String -> Int
sumOfDigit = foldr ((+) . (flip (-) 48) . ord) 0

superDigit :: Int -> Int
superDigit n
    | n < 10    = n
    | otherwise = superDigit $ sumOfDigit (show n)

solve :: [String] -> Int
solve [n, k] = superDigit $ sumOfDigit n * read k

main :: IO()
main = getLine >>= putStrLn . show . solve . words