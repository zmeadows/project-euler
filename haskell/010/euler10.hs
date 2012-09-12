isPrime x = all (\y -> mod x y /= 0) [2..(round $ sqrt q)]
    where q = (fromIntegral x) :: Float


answer = sum $! [ u | u <- [3,5..2000000], isPrime u ]

main = print (answer + 2)
