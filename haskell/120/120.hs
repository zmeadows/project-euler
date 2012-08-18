function a = maximum $ (\q -> getRep (take 2 q) (drop 2 q)) $ map (\n -> mod (((a-1)^n) + ((a+1)^n)) (a^2)) [1..]

findRep x = let (a,b) = halves x in a == b
 where halves = splitAt (div (length x) 2)

getRep x xs
  | findRep x = take (div (length x) 2) x
  | otherwise = getRep (x ++ (take 2 xs)) (drop 2 xs)

main = print $ sum $ map function [3..1000]
