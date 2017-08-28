import Control.Monad

mend :: Integer -> Integer
mend = flip mod 100000007

fibo' :: (Eq a, Num a) => a -> Integer -> Integer -> [Integer]
fibo' 0 x _ = [x]
fibo' n x y = x : fibo' (n - 1) (mend y) (mend $ x + y)

fibo :: (Eq a, Num a) => a -> [Integer]
fibo n = fibo' n 0 1

fibo10000 :: [Integer]
fibo10000 = fibo 10000

solve :: Int -> Integer
solve = (!!) fibo10000

getInt :: IO Int
getInt = getLine >>= return . read

main :: IO()
main =
    getInt >>= flip replicateM getInt
           >>= mapM_ (putStrLn . show . solve)