import Data.List

answer = head [ x | x <- tests, crit x]
    where tests = filter (\q -> (read (take 3 (show q)) :: Int) > 165) [1..]

crit x = shso (2*x) && shso (3*x) && shso (4*x) && shso (5*x) && shso (6*x)
    where shso q = (sort $ show q) == (sort $ show x)

main = print answer
