import Control.Monad

cross :: Num a => (a,a) -> (a,a) -> a
cross (ax, ay) (bx, by) = ax * by - ay * bx

lsToTup :: [a] -> (a,a)
lsToTup xs = (head xs, last xs)

area :: [(Double,Double)] -> Double
area xss = ((*) 0.5 . abs . sum) (zipWith cross xss (last xss:xss))

solve :: [[Double]] -> Double
solve = area . map lsToTup

readInt :: IO Int
readInt = getLine >>= return . read

main :: IO ()
main =
  readInt >>= flip replicateM getLine
          >>= print . solve . map (map read . words)