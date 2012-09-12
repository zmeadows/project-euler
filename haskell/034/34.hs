fac x = product [1..x]

numToList :: Int -> [Int]
numToList x = map (\q -> read q :: Int) $ map toList $ show x
    where toList a = [a]

facCheck x
    | x == (sum $ map fac (numToList x)) = True
    | otherwise = False

answer = sum $ filter facCheck [3..2500000]

main = print answer
