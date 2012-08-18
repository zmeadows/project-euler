import Euler

e = take 99 $ concat $ map (\n -> [1.0,n,1.0]) [2.0,4.0..]

test x [] = x
test x (y:ys) = x + (1.0 / (test y ys))
