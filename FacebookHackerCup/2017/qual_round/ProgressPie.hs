import Control.Monad
import Control.Applicative

factor :: Double
factor = 50

generate :: (Num a, Enum a) => a -> [a]
generate n = [1 .. n]

list2tup :: [a] -> (a, a)
list2tup xs = (head xs, last xs)

normal :: Double -> Double
normal x = (x - factor) / factor

getSolve :: [Double] -> String
getSolve xs = if and [percent <= head xs, distance < 1] then "black" else "white"
  where
    normaler = normal <$> tail xs
    angle    = uncurry atan2 . list2tup $ normaler
    percent  = (angle + if angle < 0 then 2 * pi else 0) * factor / pi
    distance = sqrt . sum . map (\x -> x * x) $ normaler

solve :: (Int, [Double]) -> (Int, String)
solve (n, xs) = (n, getSolve xs)

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO [Double]
getCase = getLine >>= return . map read . words

printCase :: (Int, String) -> IO ()
printCase (n, str) = putStrLn . concat $ ["Case #", show n, ": ", str]

main :: IO ()
main = getInt >>= \n -> replicateM n getCase
              >>= mapM_ (printCase . solve) . zip (generate n)