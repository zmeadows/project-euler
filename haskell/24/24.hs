import Data.List (delete)

permutationsOf [] = [[]]
permutationsOf xs = [x:xs' | x <- xs, xs' <- permutationsOf (delete x xs)]

format [] n = 0
format (x:xs) n = x*10^n + (format xs (n - 1))

answer = (permutationsOf [0..9]) !! 999999

main = print $ format answer 9
