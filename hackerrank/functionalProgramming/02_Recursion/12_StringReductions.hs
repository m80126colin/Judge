import Control.Monad

solve :: Eq a => [a] -> [a]
solve [] = []
solve (x:xs) = x : (solve $ filter (/= x) xs)

main :: IO()
main = getLine >>= putStrLn . solve