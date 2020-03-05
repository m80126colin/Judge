import Control.Monad
import Control.Applicative

{-

-- A brutal way by Integer calculation.

divisor :: Integral a => a
divisor = 1000000007

solve :: Integral a => [[a]] -> a
solve xs = mod (gcd (head ys) (last ys)) divisor
  where ys = map (foldr (*) 1) xs

-}

seige :: Integral a => a -> [a]
seige n
  | n < 2     = []
  | otherwise = primes ++ filter ps [sqn + 1 .. n]
  where sqn    = floor . sqrt . fromIntegral $ n
        primes = seige sqn
        ps x   = flip all primes $ (/=) 0 . mod x

count :: Integral a => a -> a -> a
count 0 _ = 0
count n c = if mod n c == 0 then 1 + count (div n c) c else 0

factor :: Integral a => a -> a -> [a]
factor p n = count n <$> seige p

factorList :: Integral a => a -> [a] -> [a]
factorList p = foldr1 (zipWith (+)) . map (factor p)

gcdByFactorList :: Integral a => [[a]] -> [a]
gcdByFactorList = foldr1 (zipWith min)

solve :: [[Int]] -> Int
solve = findResidueFromFactor . gcdByFactorList . map (factorList limit)
  where
    divisor :: Int
    divisor = 1000000007

    limit :: Int
    limit = 10000
    
    findResidueFromFactor :: [Int] -> Int
    findResidueFromFactor = foldr (\a -> flip mod divisor . (*) a) 1 . concat . zipWith (flip replicate) (seige limit)

main :: IO ()
main =
  getLine >>= \_ ->
  getLine >>= \x ->
  getLine >>= \_ ->
  getLine >>= \y -> (print . solve . map (map read . words)) [x, y]