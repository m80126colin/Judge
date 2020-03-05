import Control.Monad
import Data.List

generate :: (Num a, Enum a) => a -> [a]
generate n = [1 .. n]

trans :: Int -> Int
trans = ceiling . (/) 50 . fromIntegral

prefixes :: [a] -> [[a]]
prefixes xs = (take <$> [1 .. length xs]) <*> [xs]

takePrefix :: [Int] -> [Int]
takePrefix xs = takeWhile (<= (length xs)) xs

solve :: [Int] -> Int
solve = length . takePrefix . map sum . prefixes . sort . map trans

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO [Int]
getCase = getInt >>= flip replicateM getInt

printCase :: (Int, Int) -> IO ()
printCase (t, n) = putStrLn . concat $ ["Case #", show t, ": ", show n]

main :: IO ()
main = getInt >>= \t -> replicateM t getCase
              >>= mapM_ printCase . zip (generate t) . map solve