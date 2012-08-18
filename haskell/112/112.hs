import Euler
import Data.List

isBouncy x = isBouncy' $ digitsOf x
    where isBouncy' z = (z /= sort z) && (z /= (reverse $ sort z))

bounceRatio = scanl (\(a,b) x -> if isBouncy x then (a+1,b) else (a,b+1)) (0,0) [1..]

main = print $ findIndex (\(x,y) -> ((x/(x+y)) * 100) == 99) bounceRatio
