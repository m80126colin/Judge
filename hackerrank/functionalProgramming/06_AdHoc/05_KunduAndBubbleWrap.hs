solve :: (Integral a, Floating b) => [a] -> b
solve = undefined

main :: IO ()
main = getLine >>= print . solve . map read . words