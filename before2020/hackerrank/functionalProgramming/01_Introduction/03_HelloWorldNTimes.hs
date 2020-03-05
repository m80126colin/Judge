hello_worlds n = do -- Complete this function
   if n > 1 then hello_worlds (n - 1) else return ()
   putStrLn "Hello World"