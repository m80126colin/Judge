import Control.Monad

count :: (Integral a, Num b) => a -> a -> (a, b)
count n k = count' n k 0
    where
        count' :: (Integral a, Num b) => a -> a -> b -> (a, b)
        count' n k cnt
            | mod n k == 0 = count' (div n k) k (cnt + 1)
            | otherwise    = (n, cnt)

factor :: Integer -> [(Integer, Integer)]
factor = flip factor' 2
    where
        factor' :: Integral a => a -> a -> [(a, a)]
        factor' 1 _ = []
        factor' n k
            | k * k > n    = [(n, 1)]
            | mod n k == 0 = (k, cnt) : factor' res k
            | otherwise    = factor' n (k + 1)
            where (res, cnt) = count n k

solve :: Foldable t => t Integer -> Integer
solve = product . map ((+1) . snd) . factor . foldl1 gcd

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO [Integer]
getCase = getLine >>= return . map read . words

main = getInt >>= flip replicateM getCase
              >>= mapM_ (putStrLn . show . solve)