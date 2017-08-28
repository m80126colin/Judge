import Data.List
import Control.Monad

{-
    positionGroup: O(n log n)
        count the number of elements and represent with the order of the
        appearance to the first time.
-}
positionGroup :: Ord a => [a] -> [(a, Int)]
positionGroup = map final . sortBy posCmp . map cnt . groupBy gmp . sortBy cmp . flip zip [0 ..]
    where
        cmp :: Ord a => (a, b) -> (a, c) -> Ordering
        cmp (x, _) (y, _)
            | x < y     = LT
            | x > y     = GT
            | otherwise = EQ
        posCmp :: Ord t => (a, b, t) -> (c, d, t) -> Ordering
        posCmp (_, _, x) (_, _, y)
            | x < y     = LT
            | x > y     = GT
            | otherwise = EQ
        gmp :: Eq a => (a, b) -> (a, c) -> Bool
        gmp (x, _) (y, _) = x == y
        cnt :: Ord t => [(a, t)] -> (a, Int, t)
        cnt xs = (fst $ head xs, length xs, minimum $ map snd xs)
        final :: (a, b, c) -> (a, b)
        final (a, b, _) = (a, b)

solve :: Ord a => (Int, [a]) -> [a]
solve (k, xs) = map fst . filter ((>= k) . snd) $ positionGroup xs

getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO (Int, [String])
getCase =
    getLine >>= \x ->
    getLine >>= \y ->
        return (read . last $ words x, words y)

printCase :: [String] -> String
printCase [] = "-1"
printCase xs = unwords xs

main :: IO()
main =
    getInt >>= flip replicateM getCase
           >>= mapM_ (putStrLn . printCase . solve)