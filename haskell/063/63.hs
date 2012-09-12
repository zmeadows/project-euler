nPowers x = filter (\t -> length t == x)
            $ takeWhile (\r -> length r <= x)
            $ map (\q -> show $ q^x) [1..]

main = print $ length $ concat $ takeWhile (/= []) $ map nPowers [1..]
