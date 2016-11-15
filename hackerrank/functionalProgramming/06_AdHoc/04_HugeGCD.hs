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

count' :: Int -> Int -> Int -> Int
count' n c t
  | n < c            = t
  | (/=) (mod n c) 0 = t
  | otherwise        = count' (div n c) c (t + 1)

count :: Int -> Int -> Int
count n c = count' n c 0

factor :: Int -> Int -> [Int]
factor p = zipWith (flip count) (primes p) . repeat

solve :: [[Int]] -> Int
solve = findResidueFromFactor . factorGcd . map factorList
  where
    divisor :: Int
    divisor = 1000000007

    limit :: Int
    limit = 10000

    factorList :: [Int] -> [Int]
    factorList = foldr1 (zipWith (+)) . map (factor limit)

    factorGcd :: [[Int]] -> [Int]
    factorGcd = foldr1 (zipWith min)
    
    findResidueFromFactor :: [Int] -> Int
    findResidueFromFactor = foldr (\a -> flip mod divisor . (*) a) 1 . concat . zipWith (flip replicate) (primes limit)

main :: IO ()
main =
  getLine >>= \_ ->
  getLine >>= \x ->
  getLine >>= \_ ->
  getLine >>= \y -> (print . solve . map (map read . words)) [x, y]