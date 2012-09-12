import Data.List

triangle = [ x*(x + 1) `div` 2 | x <- [286..] ]

pentagonal = [ x*((3*x) - 1) `div` 2 | x <- [166..99999] ]

hexagonal = [ x*((2*x)-1) | x <- [144..99999] ]

answer = find (\x -> (elem x pentagonal) && (elem x hexagonal)) triangle

main = print answer
