import Euler

test x = any ( == x ) $ takeWhile (\n -> n <= x && n /= 1) $ map (\n -> (sum $ digitsOf x)^n) [2..]

main = print $ (filter test [1..]) !! 15
