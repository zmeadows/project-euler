import Data.List
import Primes
import Euler (digitsOf, digitsIn)


digitCands n = map (\x -> map (\q -> digitsIn n - q - 1) x)  $ idenInd n
idenDigs n = map head $ filter (\x -> length x > 1) $ group $ sort $ digitsOf n
idenInd n = map (\x -> elemIndices x $ digitsOf n) $ idenDigs n
tenPowers xs = sum $ map (\x -> 10^x) xs
powerList n = zip (idenDigs n) (map tenPowers $ digitCands n)

makePrimeCandList n = map primeCandCreate $ powerList n
    where primeCandCreate (a, x) | a == firstDigit = zipWith (+) (scanl1 (+) $ replicate 9 x) (replicate 9 (n - (a) * x))
                                 | a == 0 = [n] ++ zipWith (+) (scanl1 (+) $ replicate 9 x) (replicate 9 (n - a * x))
                                 | otherwise = zipWith (+) (scanl1 (+) $ replicate 9 x) (replicate 9 (n - a * x))
          firstDigit = head $ digitsOf n

finalCand n
  | length primeCandListCheck == 0 = 0
  | length primeCandListCheck == 1 = head primeCandListCheck
  | otherwise = maximum primeCandListCheck
  where primeCandListCheck = map length $ map (filter isPrime) $ makePrimeCandList n

main = print $ elemIndex 8 $ map finalCand primes
