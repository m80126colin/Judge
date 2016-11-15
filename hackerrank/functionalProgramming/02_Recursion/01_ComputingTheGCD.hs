gcd' :: Integral a => a -> a -> a
gcd' m 0 = m
gcd' m n = gcd' n (mod m n)