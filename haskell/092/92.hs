import Euler

main = print $ length $ filter (/= 1) $ map terminal $ map sqSum $ [2..9999999]
         where sqSum x = iterate (\r -> sum $ map (\q -> q*q) $ digitsOf r) x
               terminal x = last $ takeUntil (\q -> q == 1 || q == 89) x
