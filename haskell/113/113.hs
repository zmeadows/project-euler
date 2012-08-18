import Euler
import Data.List

isBouncy x = isBouncy' $ digitsOf x
    where isBouncy' z = (z /= sort z) && (z /= (reverse $ sort z))

main = print $ length $ filter isBouncy [1..(10^100)]
