solve :: Integral a => [a] -> a
solve = foldr lcm 1

main :: IO ()
main =
  getLine >>= \x ->
  getLine >>= print . solve . map read . words