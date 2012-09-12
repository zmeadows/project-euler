import Euler
import Data.List

sumComp x y
  | sum x > sum y = GT
  | otherwise = LT

primes' = [ [a,b,c,d,e] | a <- primes, b <- primes, c <- primes, d <- primes, e <- primes ]

concats x = [ read ((show a) ++ (show b)) :: Int | a <- x, b <- x ]
