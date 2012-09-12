import Data.List

isPrime x = not $ any (\y -> mod x y == 0) [2..(getFloor x)]
    where getFloor q = ceiling (sqrt (fromIntegral q :: Float))

rotations x = take (length (show x)) $ iterate rotate x
    where rotate = (\q -> read ((last (show q)) : (init (show q))) :: Int)

answer = length $ filter isCircular $ [3,5..999999]
  where isCircular x = all isPrime $! rotations x

main = print $ answer + 1
