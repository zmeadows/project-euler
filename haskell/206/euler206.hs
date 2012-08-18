import Data.List

test x
  |  length q == 19
     && q !! 0 == '1'
     && q !! 2 == '2'
     && q !! 4 == '3'
     && q !! 6 == '4'
     && q !! 8 == '5'
     && q !! 10 == '6'
     && q !! 12 == '7'
     && q !! 14 == '8'
     && q !! 16 == '9'
     && q !! 18 == '0' = True
  | otherwise = False
 where q = (show x)

answer = find (\x -> test (x^2)) [1010101010,1010101012..]

main = print answer
