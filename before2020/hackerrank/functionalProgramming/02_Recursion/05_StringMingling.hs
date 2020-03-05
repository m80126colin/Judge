{-
mingle :: [a] -> [a] -> [a]
mingle l = concat . zipWith (\a b -> [a, b]) l
-}

mingle :: [a] -> [a] -> [a]
mingle [] _ = []
mingle _ [] = []
mingle (x:xs) (y:ys) = x:y:mingle xs ys

main :: IO ()
main = getLine >>= \x ->
       getLine >>= \y ->
         putStrLn (mingle x y)