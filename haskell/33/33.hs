import Euler

fracs = [ (a,b) | a <- set, b <- set, b > a, cur a b]
  where set = filter (\n -> mod n 10 /= 0) [10..100]

cur x y = (x'' == y' && fx/fy == x'/y'') || (x' == y'' && fx/fy == x''/y')
  where x'  = fromIntegral (mod x 10) :: Float
        y'  = fromIntegral (mod y 10) :: Float
        x'' = fromIntegral (div x 10) :: Float
        y'' = fromIntegral (div y 10) :: Float
        fx  = fromIntegral x :: Float
        fy  = fromIntegral y :: Float

main = print (den `div` (gCD den num))
  where den = product $ map snd fracs
        num = product $ map fst fracs
