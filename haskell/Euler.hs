module Euler where

import qualified Data.Char as C
import qualified Data.List as L
import qualified Data.Set  as S

digitsIn x = length $ show x

digitsOf x = map C.digitToInt $ show x

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs@(x:xt) ys@(y:yt) =
  case compare x y of
    LT -> x : (merge xt ys)
    EQ -> x : (merge xt yt)
    GT -> y : (merge xs yt)

diff :: (Ord a) => [a] -> [a] -> [a]
diff xs@(x:xt) ys@(y:yt) =
  case compare x y of
    LT -> x : (diff xt ys)
    EQ -> diff xt yt
    GT -> diff xs yt

primes, nonprimes :: [Integer]
primes    = [2, 3, 5] ++ (diff [7, 9 ..] nonprimes)
nonprimes = foldr1 f . map g . tail $ primes
  where
    f (x:xt) ys = x : (merge xt ys)
    g p         = [ n * p | n <- [p, p + 2 ..]]

takeUntil :: (a -> Bool) -> [a] -> [a]
takeUntil p []       = []
takeUntil p (x:xs)
    | p x         = [x]
    | otherwise   = x : takeUntil p xs

divisors :: Integer -> [Integer]
divisors n = nub' $ set ++ (map (\q -> div n q) set)
 where divisors' x = filter (\n -> mod x n == 0) [1..getSqRt (fromIntegral x :: Float)]
       getSqRt x = (ceiling $ sqrt x) :: Integer
       set = L.union (divisors' n) (primeFactors n)

propDivisors :: Integer -> [Integer]
propDivisors x = init $ divisors x

gCD :: (Num a, Ord a) => a -> a -> a
gCD x y = snd $ fromJust $ L.find (\(q,r) -> q == 0 || r == 0) $ iterate euclid (x,y)
  where euclid (a,b)
         | a == 0 = (b,0)
         | b == 0 = (a,0)
         | a >= b = ((a-b),b)
         | b > a = (a,(b-a))
        fromJust (Just m) = m

gCD' x y = head $ L.intersect x' y'
  where x' = reverse $ L.sort $ divisors x
        y' = reverse $ L.sort $ divisors y

phi 1 = 1
phi x = foldl (\acc (a,b) -> acc * ((a-1) * (a^(b-1)))) 1 $ facGroup x
  where facGroup r = map (\n -> (head n, length n)) $ L.group $ primeFactors r

primeFactors = pf primes
  where
    pf ps@(p:ps') n
     | p * p > n = [n]
     | r == 0    = p : pf ps q
     | otherwise = pf ps' n
     where (q, r) = n `divMod` p

isPrime n
  | n > 1 = primeFactors n == [n]
  | otherwise = False

nub' :: [Integer] -> [Integer]
nub' = S.toList . S.fromList

recurringCycle d = remainders d 10 []
remainders d 0 rs = 0
remainders d r rs = let r' = mod r d
                    in case L.elemIndex r' rs of
                         Just i  -> i + 1
                         Nothing -> remainders d (10*r') (r':rs)

fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
