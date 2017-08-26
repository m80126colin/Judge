import Control.Monad

{-

-- This solution will TLE.

pentagonal :: Integral a => a -> a -> a -> [a]
pentagonal m n x
  | m == n    = [x]
  | otherwise = x:pentagonal (m + 1) n (x + 3 * m - 2)

penta :: Integral a => [a]
penta = pentagonal 1 100001 0

solve :: Integral a => Int -> a
solve = (!!) penta

-}

solve :: Integral a => a -> a
solve n = div (3 * n * n - n) 2

main :: IO ()
main =
  getLine >>= flip replicateM getLine . read
          >>= mapM_ (print . solve . read)