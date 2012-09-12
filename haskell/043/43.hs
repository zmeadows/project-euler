import Euler
import Data.List

poss = filter (\x -> length (show x) == 10) $ map (\x -> read x :: Int) $ permutations "9876543210"

cutUp x = cutUp' (tail (digitsOf x)) []
  where cutUp' x y
          | length x < 3 = reverse y
          | otherwise = cutUp' (tail x) ((take 3 x) : y)

isSub x = all (\(a,b) -> (mod (read (concat $ map show a) :: Int) b) == 0) $ zip (cutUp x) $ map (\x -> fromInteger x :: Int) primes

main = print $ sum $ filter isSub poss
