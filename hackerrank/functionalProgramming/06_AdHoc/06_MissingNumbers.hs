import Data.List
import Control.Monad

count :: (Eq a, Ord a) => [a] -> [(a, Int)]
count = map f . group . sort
    where f ys = (head ys, length ys)

solve' :: (Ord a, Ord b) => [(a, b)] -> [(a, b)] -> [a]
solve' _        []         = []
solve' []       ya         = map fst ya
solve' xa@(x:xs) ya@(y:ys)
    | fst x < fst y = solve' xs ya
    | fst x > fst y = fst y : solve' xa ys
    | snd x < snd y = fst y : solve' xs ys
    | otherwise     = solve' xs ys

solve :: ([Int], [Int]) -> [Int]
solve (xs, ys) = solve' (count xs) (count ys)

strToInts :: String -> [Int]
strToInts = map read . words

intsToStr :: [Int] -> String
intsToStr = unwords . map show

main =
    getLine >>= \_ ->
    getLine >>= \x ->
    getLine >>= \_ ->
    getLine >>= \y ->
        putStrLn . intsToStr . solve $ (strToInts x, strToInts y)