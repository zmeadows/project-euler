import Data.Char (digitToInt)
 
intSqrt :: Integer -> Integer
intSqrt n = bsearch 1 n
    where
      bsearch l u = let m = (l+u) `div` 2
                        m2 = m^2
                    in if u <= l
                       then m
                       else if m2 < n
                            then bsearch (m+1) u
                            else bsearch l m
 
problem_80 :: Int
problem_80 = sum [f r | a <- [1..100],
                        let x = a * e,
                        let r = intSqrt x,
                        r*r /= x]
    where
      e = 10^202
      f = sum . take 100 . map digitToInt . show
