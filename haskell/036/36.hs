decToBin x = reverse $ decToBin' x
  where
    decToBin' 0 = []
    decToBin' y = let (a,b) = quotRem y 2 in [b] ++ decToBin' a

isPalin x = reverse x == x

answer = sum $ filter (\x -> isPalin (show x) && isPalin (concat $ map show $ decToBin x)) [1..999999]

main = print answer
