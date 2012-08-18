import Euler

answer = sum $ takeWhile (<= 4000000) $ filter (\x -> even x) fibs

main = print answer
