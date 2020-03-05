f :: [Int] -> [Int]
f = map snd . filter (even . fst) . zip [1..] -- Fill up this Function