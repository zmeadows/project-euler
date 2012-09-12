answer = sum [ x | x <- [2..99999], (sum (map (\r -> r^5) (map (\q -> read q ::Int) (map toList (show x))))) == x ]
               where toList x = [x]

main = print answer
