fibs q = fib 0 1 2
  where fib x y i = do let z = x + y
                       if i == (q + 1)
                          then z
                          else fib y z (i + 1)
