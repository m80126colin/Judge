fib :: Int -> Int
fib n = fib' n 0 1

fib' :: Int -> Int -> Int -> Int
fib' 1 a _ = a
fib' n a b = fib' (n - 1) b (a + b)