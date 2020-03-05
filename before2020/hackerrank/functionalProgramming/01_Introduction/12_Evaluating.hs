import Control.Applicative
import Control.Monad
import System.IO

eva :: Double -> Double
eva x = (1 +) $ foldr (\a b -> (b + 1) * x / a) 0 [1..9]

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    getMultipleLines n >>= mapM_ (print . eva)

getMultipleLines :: Int -> IO [Double]
getMultipleLines n
  | n <= 0 = return []
  | otherwise = do
      x_tmp <- getLine
      xs <- getMultipleLines (n - 1)
      let x = read x_tmp :: Double
      let ret = x:xs
      return ret