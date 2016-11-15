import Control.Applicative

lstToTup :: [a] -> (a, a)
lstToTup xs = (head xs, last xs)

half :: [a] -> ([a], [a])
half xs = lstToTup (map uncurry [take, drop] <*> [(n, xs)])
  where n = (flip div 2 . length) xs

makeDash :: Int -> String -> String
makeDash len str = concat [fst dash, str, snd dash]
  where dash = (half . replicate (len - length str)) '_'

sierpinski :: Int -> Int -> [String]
sierpinski 0 len = [ makeDash len (replicate i '1') | i <- [1, 3 .. len] ]
sierpinski n len = concat [upper, lower]
  where tri   = sierpinski (n - 1) (div len 2)
        upper = map (makeDash len) tri
        lower = zipWith (flip (++) . (++) "_") tri tri

solve = flip sierpinski 63

main = getLine >>= mapM_ putStrLn . solve . read