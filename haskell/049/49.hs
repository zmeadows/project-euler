import Data.List

perms x y
  | x+y+y > 9999 = Nothing
  | isPrime x && isPrime (x+y) && isPrime (x+y+y) = Just (x,x+y,x+y+y)
  | otherwise = Nothing

getPerms x = filter arePerms $ getJusts $ map (perms x) [2..q]
    where q = div (10000 - x) 2

isPrime x = elem x primes

primes = filter isPrime' [1001,1003..9999]
    where isPrime' x = (not . (any (== 0))) $ map (mod x) [2..((div x 2) + 1)]

getJusts x = filter (/= Nothing) x

arePerms (Just (a,b,c)) = ((sort $ show a) == (sort $ (show b)) && (sort $ show a) == (sort $ show c))

main = print $ take 3 $ nub $ map getPerms primes
