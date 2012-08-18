import Euler

vars = [ (a,b) | a <- set, b <- (filter (\n -> elem (abs n) (takeWhile (<=(abs n)) primes)) set) ]
  where set = [(-999)..999]

funcs = map (\(a,b) -> (a,b,quad a b)) vars
  where quad a b n = (n^2) + (a*n) + b

primeCount m = length $ takeWhile (\n -> elem n primes') m
  where primes' = takeWhile (<= (maximum m)) primes

main = print $ maximum $ map get funcs
  where get (a,b,f) = (primeCount (map f [0..]),a,b)
