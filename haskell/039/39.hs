import Data.List

perSol = [ (a,b,c) | a <- [1..1000], b <- [1..1000], c <- [1..1000], (a^2) + (b^2) == (c^2), a+b+c <= 1000 ]

--answer = findIndex (== (maximum test)) $! test

--test = map length (map perSol [1..1000])

--main = print test

tupSum (x,y,z) = x+y+z

answer = foldl1 findBig $ group $ sort $ map tupSum perSol

findBig x y
  | length x > length y = x
  | length x < length y = y
  | otherwise = x

main = print answer
