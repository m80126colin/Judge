import Control.Monad
import Control.Applicative

{-
catalans :: Integral a => a -> [a]
catalans 1 = [1, 1]
catalans n = xs ++ [flip mod m . foldr (+) 0 $ zipWith (*) xs (reverse xs)]
  where m  = 100000007
        xs = catalans $ n - 1
-}

catalans :: Integral a => a -> [a]
catalans 1 = [1, 1]
catalans n = xs ++ [x]
  where xs = catalans $ n - 1
        x  = div (2 * (2 * n - 1) * (last xs)) (n + 1)

catalan :: Integral a => [a]
catalan = flip mod m <$> catalans 1000 where m = 100000007

solve :: Integral a => Int -> a
solve = (!!) catalan

main :: IO ()
main =
  getLine >>= flip replicateM getLine . read
          >>= mapM_ (print . solve . read)