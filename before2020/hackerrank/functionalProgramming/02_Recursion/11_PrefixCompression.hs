import Control.Monad

solve' :: Eq a => [a] -> [a] -> [a] -> [[a]]
solve' []        ys        pre = [reverse pre, [], ys]
solve' xs        []        pre = [reverse pre, xs, []]
solve' xa@(x:xs) ya@(y:ys) pre
  | x == y    = solve' xs ys (x:pre)
  | otherwise = [reverse pre, xa, ya]

solve :: Eq a => ([a], [a]) -> [[a]]
solve (xs, ys) = solve' xs ys []

getCase :: IO (String, String)
getCase = getLine >>= \x ->
          getLine >>= \y -> return (x, y)

printCase :: [String] -> IO()
printCase = mapM_ (putStrLn . pt)
  where
    pt xs
      | length xs == 0 = show (length xs)
      | otherwise      = show (length xs) ++ " " ++ xs

main :: IO()
main = getCase >>= printCase . solve