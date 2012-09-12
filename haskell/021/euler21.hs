import Data.List

propDivSum x = sum [ r | r <- [1..(div x 2)], mod x r == 0 ]

amicablePairs = sum $ map (\(x,y) -> x + y) $ nub $ concat
                $ filter (\x -> length x == 2) $ group $ sort
                $ map orderPair [ (x,y) | (x,y) <- zip [1..9999] $ map propDivSum [1..9999] ]

orderPair (x,y)
  | x > y     = (y,x)
  | otherwise = (x,y)

main = print amicablePairs
