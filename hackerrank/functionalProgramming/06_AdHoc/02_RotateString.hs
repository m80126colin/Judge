import Control.Monad
import Control.Applicative

rotate :: Int -> [a] -> [a]
rotate n xs = concat ([drop, take] <*> [n] <*> [xs])

joinList :: [a] -> [[a]] -> [a]
joinList sep xs = head xs ++ foldr ((++) . (++) sep) [] (tail xs)

solve :: String -> String
solve xs = joinList " " (rotate <$> [1 .. length xs] <*> [xs])

main :: IO ()
main =
  getLine >>= return . read
          >>= flip replicateM getLine
          >>= mapM_ (putStrLn . solve)