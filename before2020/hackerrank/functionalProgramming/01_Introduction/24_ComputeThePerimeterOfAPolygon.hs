import Control.Monad

inner :: Num a => [a] -> [a] -> a
inner xs ys = sum (zipWith (*) xs ys)

vector :: Num a => [a] -> [a] -> [a]
vector = zipWith (-)

solve :: [[Double]] -> Double
solve xss = (sum . map sqrt) (zipWith inner vss vss)
  where vss = zipWith vector xss (last xss:xss)

readInt :: IO Int
readInt = do
  getLine >>= return . read

main = do
  readInt >>= flip replicateM getLine
          >>= print . solve . map (map read . words)