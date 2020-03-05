inner :: Num a => [a] -> [a] -> a
inner xs ys = sum $ zipWith (*) xs ys

poly :: (Floating a, Integral b) => [a] -> [b] -> a -> a
poly as bs x = inner as (map ((**) x . fromIntegral) bs)

interval :: (Fractional a, Enum a) => a -> a -> a -> [a]
interval l r d = [l + 0.5 * d, l + 1.5 * d .. r - 0.5 * d]

-- circ :: Double -> Double
circ = (*) pi . flip (**) 2

mapPoly :: (Floating a, Enum a, Integral b) => ([a] -> c) -> a -> a -> a -> [a] -> [b] -> c
mapPoly f d l r a b = (f . map (poly a b)) (interval l r d)

delta :: Double
delta = 0.001

area :: Double -> Double -> [Double] -> [Integer] -> Double
area = mapPoly ((*) delta . sum) delta

volume :: Double -> Double -> [Double] -> [Integer] -> Double
volume = mapPoly ((*) delta . sum . map circ) delta

-- This function should return a list [area, volume].
solve :: Int -> Int -> [Int] -> [Int] -> [Double]
solve l r a b = [area l' r' a' b', volume l' r' a' b'] --Complete this function--
  where [l', r'] = map fromIntegral [l, r]
        a'       = map fromIntegral a
        b'       = map fromIntegral b