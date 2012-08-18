import Data.List

isPandigital x = sort x == "123456789"

some q = map last $ filter (\x -> (sort $ concat $ map show x) == "123456789") $ takeWhile (\r -> (length $ concat $ map show r) < 10) $ map (\x -> [q,x,q*x]) [1..]

main = print $ sum $ nub $ concat $ map some [1..1000]
