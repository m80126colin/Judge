import Control.Monad

solve :: String -> [(Char, Int)]
solve []        = []
solve as@(x:xs) = (x, length a) : solve b
    where (a, b) = span (== x) as

outFormat :: [(Char, Int)] -> String
outFormat = concat . map (\(x, y) -> if y /= 1 then x : show y else [x])

main :: IO()
main = getLine >>= putStrLn . outFormat . solve