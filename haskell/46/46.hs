import Euler
import Data.List
goldBach x = null $ [ (a,q) | a <- (takeWhile (< x) primes), q <- map (\r -> 2*r*r) [1..(div x 2)], a < x, q < x, a+q == x ]
main = print $ head $ filter goldBach $ filter odd nonprimes
