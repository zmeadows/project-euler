import Euler
import Data.List

test = group $ map (\n -> length $ group $ primeFactors n) [1..]

main = print $ (length $ concat $ fst cut) + 1
  where fin = let (Just a) = findIndex (== [4,4,4,4]) test in a
        cut = splitAt fin test
