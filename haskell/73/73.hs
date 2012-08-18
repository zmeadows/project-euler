import Euler
import Data.List

--mains = [ a/b | a <-

hCF a b = head $ intersect (divisors a) (divisors b)
