import Euler
import Data.List

corners = tail
          $ scanl (\x f -> f x) 1
          $ concat
          $ map (\x -> map (\y -> (+) y) x)
          $ map (\x -> take 4 $ repeat x) [2,4..]

answer = tail $ scanl (\(a,b) cor -> if elem cor (takeWhile (<= cor) primes) then (a+1,b+1) else (a,b+1)) (0,0) corners

main = print $ find (\(a,b) -> (a/b) < 0.14) $ answer
