import Data.List

polyNums = filter (\x -> mod x 100 > 9) $ nub $ triangle ++ square ++ pentagonal ++ hexagonal ++ heptagonal ++ octagonal
  where triangle   = mapFunc (\n -> n*(n+1) `div` 2) \\ hexagonal
        square     = mapFunc (\n -> n*n)
        pentagonal = mapFunc (\n -> n*(3*n-1) `div` 2)
        hexagonal  = mapFunc (\n -> n*(2*n-1))
        heptagonal = mapFunc (\n -> n*(5*n-3) `div` 2)
        octagonal  = mapFunc (\n -> n*(3*n-1) `div` 2)
        mapFunc f = filter (> 999) $ takeWhile (< 10000) $ map f [1..]

heads 100 = []
heads n = map sort $ (filter (\x -> x `div` 100 == n) polyNums) : heads (n+1)

tailS 100 = []
tailS n = map sort $ (filter (\x -> x `mod` 100 == n) polyNums) : tailS (n+1)

--findCycles n = 
