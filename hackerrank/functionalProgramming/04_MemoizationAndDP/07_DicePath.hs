import Control.Monad

{-
    Dice {Top} {Bottom} {Left} {Right} {Front} {Back}
-}
data Dice a = Dice a a a a a a deriving (Show, Eq)

listify :: Dice a -> [a]
listify (Dice top btm lft rht fnt bck) = [top, btm, lft, rht, fnt, bck]

instance (Ord a) => Ord (Dice a) where
    compare d1 d2 = if null res then EQ else head res
        where
            comp = zipWith compare (listify d1) (listify d2)
            res  = dropWhile (== EQ) comp

diceTop :: Dice a -> a
diceTop (Dice top btm lft rht fnt bck) = top

diceRollRight :: Dice a -> Dice a
diceRollRight (Dice top btm lft rht fnt bck) = Dice lft rht btm top fnt bck

diceRollDown :: Dice a -> Dice a
diceRollDown (Dice top btm lft rht fnt bck) = Dice bck fnt lft rht top btm

{-
    Cell {sum} {Dice config}
-}
data Cell a = Cell a (Dice a) deriving Show

cellDice :: Cell a -> Dice a
cellDice (Cell x d) = d

cellSum :: Num a => Cell a -> a
cellSum (Cell x d) = x + diceTop d

instance (Eq a) => Eq (Cell a) where
    (Cell x dx) == (Cell y dy) = and [x == y, dx == dy]

instance (Ord a, Num a) => Ord (Cell a) where
    compare cx@(Cell x dx) cy@(Cell y dy)
        | compare (cellSum cx) (cellSum cy) /= EQ = compare (cellSum cx) (cellSum cy)
        | otherwise                               = compare dx dy

cellRollRight :: Num a => Cell a -> Cell a
cellRollRight c@(Cell x d) = Cell (cellSum c) (diceRollRight d)

cellRollDown :: Num a => Cell a -> Cell a
cellRollDown c@(Cell x d) = Cell (cellSum c) (diceRollDown d)

{-
    configure DP table
-}
mapTable' :: (Eq t, Num t, Ord a, Num a) => t -> [Cell a] -> [[Cell a]]
mapTable' 0 _   = []
mapTable' m row = row : mapTable' (m - 1) (mapRow' (head row) row)
    where
        mapRow' :: (Ord a, Num a) => Cell a -> [Cell a] -> [Cell a]
        mapRow' c []     = []
        mapRow' c (x:xs) = mc : mapRow' mc xs
            where mc = max (cellRollRight c) (cellRollDown x)

mapTable :: (Eq a, Num a, Eq b, Num b) => a -> b -> [[Cell Integer]]
mapTable m n = mapTable' m . mapRowInit n $ Cell 0 initDice
    where
        initDice :: Dice Integer
        initDice = Dice 1 6 3 4 2 5

        mapRowInit :: (Eq t, Num t, Num a) => t -> Cell a -> [Cell a]
        mapRowInit 0 _ = []
        mapRowInit n c = c : mapRowInit (n - 1) (cellRollRight c)

table :: [[Integer]]
table = map (map cellSum) $ mapTable 60 60

{-
    solve
-}
solve :: [Int] -> Integer
solve [x, y] = table !! (x - 1) !! (y - 1)

{-
    IO
-}
getInt :: IO Int
getInt = getLine >>= return . read

getCase :: IO [Int]
getCase = getLine >>= return . map read . words

main :: IO()
main =
    getInt >>= flip replicateM getCase
           >>= mapM_ (putStrLn . show . solve)