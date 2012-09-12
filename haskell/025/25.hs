main = fib 0 1 2
  where fib x y i = do let z = x + y
                       if (length (show z) >= 1000)
                         then print i
                         else fib y z (i + 1)
