import Euler
import Data.List

main = print $ foldl (\(a,n) (x,y) -> let xyd = (fL x)/(fL y) in if isPerm x y && xyd < a then (xyd, x) else (a,n)) (10.0,0) phiPair
phiPair = zip [2..9999999] (map phi [2..9999999])
fL x = fromIntegral x :: Float

isPerm x y = fR x == fR y
  where fR x = sort $ digitsOf x
