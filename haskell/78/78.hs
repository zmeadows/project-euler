import Data.List

pilesOf x = let q = [1..(div x 2)] in case even x of
              True -> 1 + (sum q) + (sum (init q))
              False -> 1 + (2 * sum q)

main = print $ fmap (+1) $ findIndex (\x -> mod x 1000000 == 0) $ map pilesOf [4000..]
