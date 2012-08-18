import Euler

test = foldl (\(c,d) n -> let d' = (length $ divisors n) in if d' == d then ((c+1),d') else (c,d')) (0,0) [1..9999999]

main = print test
