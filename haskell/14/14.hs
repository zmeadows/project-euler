import Data.List

collatz x
  | even x = x `div` 2
  | odd x  = (3*x) + 1

colChain x = (takeWhile (/=1) $! iterate collatz x) ++ [1]

answer = foldl1' maxi [(500001),(500003)..999999]
          where maxi x y = if (length (colChain x)) <= (length (colChain y))
                           then y
                           else x

main = print answer
