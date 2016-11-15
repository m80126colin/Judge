import Control.Monad

{-

-- A brutal way by Integer calculation.

divisor :: Integral a => a
divisor = 1000000007

solve :: Integral a => [[a]] -> a
solve xs = mod (gcd (head ys) (last ys)) divisor
  where ys = map (foldr (*) 1) xs

-}

primes' :: [Int] -> [Int] -> [Int]
primes' []       ys = reverse ys
primes' s@(x:xs) ys
  | test      = reverse ys ++ s
  | otherwise = primes' (filter ((/=) 0 . flip mod x) xs) (x:ys)
  where test = x > (floor . sqrt . fromIntegral . last) s

primes :: Int -> [Int]
primes n = primes' [2 .. n] []

pr10000 = primes 10000

count' :: Int -> Int -> Int -> Int
count' n c t
  | n < c            = t
  | (/=) (mod n c) 0 = t
  | otherwise        = count' (div n c) c (t + 1)

count :: Int -> Int -> Int
count n c = count' n c 0

factor :: Int -> [Int]
factor = zipWith (flip count) pr10000 . repeat

divisor :: Int
divisor = 1000000007

solve :: [[Int]] -> Int
solve = foldr (\a -> flip mod divisor . (*) a) 1 . concat . zipWith (flip replicate) pr10000 . foldr1 (zipWith min) . map (foldr1 (zipWith (+)) . map factor)

main :: IO ()
main =
  getLine >>= \_ ->
  getLine >>= \x ->
  getLine >>= \_ ->
  getLine >>= \y -> (print . solve . map (map read . words)) [x, y]