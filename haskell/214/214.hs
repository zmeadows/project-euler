import Euler

totientChain n = totientChain' [n]
totientChain' ns
    | last ns == 1 = ns
    | otherwise = totientChain' $ ns ++ [phi (last ns)]

answer =  sum $ map head $ filter (\q -> length q == 25) $ map totientChain primeList
    where primeList = takeWhile (< 40000000) primes
