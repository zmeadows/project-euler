import Euler
import Data.List

abNums = filter isAb [1..28123]
  where isAb x = (sum $ propDivisors x) > x

main = print $ length $ twoCombo [1..2000] []
