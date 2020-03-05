import Control.Monad

swap :: [a] -> [a]
swap []       = []
swap (x:y:xs) = y:x:swap xs

solve :: String -> String
solve = swap

readInt :: IO Int
readInt = getLine >>= return . read

main :: IO ()
main = readInt >>= flip replicateM getLine
               >>= mapM_ (putStrLn . solve)