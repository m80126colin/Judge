import Control.Monad

newtype Count = Count [Int] deriving Show -- (R, G, Y, B)

judgeAdd :: Char -> Count -> Count
judgeAdd x (Count [a, b])
    | 'R' == x = Count [a + 1, b]
    | 'G' == x = Count [a - 1, b]
    | 'Y' == x = Count [a, b + 1]
    | 'B' == x = Count [a, b - 1]

deCount :: Count -> [Int]
deCount (Count xs) = xs

postfixCount :: String -> [Count]
postfixCount []     = []
postfixCount [x]    = [ judgeAdd x $ Count [0, 0] ]
postfixCount (x:xs) = judgeAdd x (head posts) : posts
    where posts = postfixCount xs

prefixCount :: String -> [Count]
prefixCount = reverse . postfixCount . reverse

allZero :: Count -> Bool
allZero = all (== 0) . deCount

atMost1 :: Count -> Bool
atMost1 = (all $ (<= 1) . abs) . deCount

solve :: String -> Bool
solve xs = and [allZero $ last pre, all atMost1 pre]
    where pre = prefixCount xs
          end = last pre

getInt :: IO Int
getInt = getLine >>= return . read

main :: IO()
main = getInt >>= flip replicateM getLine
              >>= mapM_ (putStrLn . show . solve)