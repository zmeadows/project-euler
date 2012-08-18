import Data.List (nub)

answer = length $ nub [ a^b | a <- [2..100], b <- [2..100] ]

main = print answer
