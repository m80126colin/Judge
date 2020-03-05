solve :: [[Int]] -> String
solve xs = if test then "YES" else "NO"
  where domain = map head xs
        test   = length domain == length (unique domain)

unique :: Eq a => [a] -> [a]
unique []     = []
unique (x:xs) = if test then ys else x:ys
  where test = (not . null . filter (x ==)) ys
        ys   = unique xs

replicateM :: Monad m => Int -> m a -> m [a]
replicateM n f = foldr g (return []) (replicate n f)
  where g a b = a >>= \x ->
                b >>= \xs ->
                return (x:xs)

readInt :: IO Int
readInt =
  getLine >>= return . read

readCase :: IO [[Int]]
readCase =
  readInt >>= flip replicateM getLine
          >>= return . map (map read . words)

main :: IO ()
main =
  readInt >>= flip replicateM readCase
          >>= mapM_ (putStrLn . solve)