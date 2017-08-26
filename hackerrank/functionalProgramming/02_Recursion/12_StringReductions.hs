import Control.Monad

solve :: String -> String
solve [] = []
solve (x:xs) = x : (solve $ filter (/= x) xs)

main :: IO()
main = getLine >>= putStrLn . solve