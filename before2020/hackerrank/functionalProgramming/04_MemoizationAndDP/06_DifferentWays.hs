import Control.Monad

ele :: [Integer]
ele = [1]

pascal' :: (Eq t, Num t) => t -> [Integer] -> [[Integer]]
pascal' 0 xs = [xs]
pascal' n xs = xs : (pascal' (n - 1) . concat . sandwich ele . zipWith adder xs . tail $ xs)
    where
        adder    a b  = mod (a + b) 100000007
        sandwich a xs = [a, xs, a]

pascal :: Integer -> [[Integer]]
pascal = flip pascal' ele

pascal1000 :: [[Integer]]
pascal1000 = pascal 1000

solve :: [Int] -> Integer
solve [a, b] = pascal1000 !! a !! b

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO [Int]
getCase = getLine >>= return . map read . words

main :: IO()
main =
    getInt >>= flip replicateM getCase
           >>= mapM_ (putStrLn . show . solve)