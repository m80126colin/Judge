f :: Int -> [Int] -> [Int]
f n = concat . map (replicate n) -- Complete this function