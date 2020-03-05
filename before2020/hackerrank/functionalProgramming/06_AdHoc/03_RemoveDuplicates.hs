unique :: Eq a => [a] -> [a]
unique []     = []
unique (x:xs) = if test then ys else x:ys
  where ys   = unique xs
        test = ((<) 0 . length) (filter (x ==) ys)

solve :: String -> String
solve = reverse . unique . reverse

main :: IO ()
main = getLine >>= putStrLn . solve