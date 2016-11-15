import Data.Char

digits :: (Integral a, Num b) => a -> a -> [b]
digits d n
  | n < d     = [fromIntegral n]
  | otherwise = digits d (div n d) ++ [fromIntegral (mod n d)]

intToString :: Integer -> String
intToString = map intToDigit . digits 10

pascal :: (Num a, Eq a, Num b) => a -> [[b]]
pascal n
  | n == 1    = [[1]]
  | otherwise = lowers ++ [zipWith (+) lst (reverse lst)]
  where lowers = pascal (n - 1)
        lst    = 0:last lowers

joinInteger :: String -> [Integer] -> String
joinInteger sep = foldr (++) "" . zipWith (++) ("" : repeat sep) . map intToString

solve :: Int -> [String]
solve = map (joinInteger " ") . pascal

main :: IO ()
main = getContents >>= mapM_ (mapM_ putStrLn) . map (solve . read) . lines