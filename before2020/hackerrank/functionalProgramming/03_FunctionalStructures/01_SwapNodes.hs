import Control.Monad

data Tree a = Nil | Node a (Tree a) (Tree a) deriving (Show, Eq)

infixTraversal :: Tree a -> [a]
infixTraversal Nil                 = []
infixTraversal (Node x left right) = concat [infixTraversal left, [x], infixTraversal right]

swapDepthKTimes :: Integral b => Tree a -> b -> Tree a
swapDepthKTimes = swapDepthKTimes' 1
  where
    swapDepthKTimes' :: Integral b => b -> Tree a -> b -> Tree a
    swapDepthKTimes' _ Nil                 _ = Nil
    swapDepthKTimes' n (Node x left right) k
      | mod n k == 0 = Node x rightTree leftTree
      | otherwise    = Node x leftTree  rightTree
      where
        leftTree  = swapDepthKTimes' (n + 1) left  k
        rightTree = swapDepthKTimes' (n + 1) right k

buildTree :: Int -> [[Int]] -> Tree Int
buildTree n xs
  | n == -1   = Nil
  | otherwise = Node n (buildTree l xs) (buildTree r xs)
  where [l, r] = xs !! (n - 1)

solve :: [[Int]] -> [Int] -> [[Int]]
solve xs = map infixTraversal . tail . reverse . foldl step [buildTree 1 xs]
  where step ts k = swapDepthKTimes (head ts) k : ts

getInt :: IO Int
getInt = getLine >>= return . read

getInts :: IO [Int]
getInts = getLine >>= return . map read . words

printCase :: [Int] -> String
printCase = unwords . map show

main :: IO()
main =
  getInt >>= flip replicateM getInts
         >>= \xs ->
  getInt >>= flip replicateM getInt
         >>= \ks -> mapM_ (putStrLn . printCase) $ solve xs ks