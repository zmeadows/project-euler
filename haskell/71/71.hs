import Euler
import Data.List

thinFrac n
  | (\(a,b,c) -> gCD (round b) (round c) == 1) q = q
  | otherwise = (0,0,0)
 where q = thinFrac' n

thinFrac' n = ((n/st),n,st)
      where st = let Just q = find (\d -> (n/d) < (3/7)) [((div (7*n) 3) - 1)..1000000] in q

main = print $ foldl (\acc x -> let q = thinFrac x in if q > acc then q else acc) (0,0,0) [1..10000]
