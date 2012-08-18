import Data.Char
import Text

main = do
  let ans = map wordVal text
  print $ length $ filter (\n -> elem n (takeWhile (<=n) triNums)) ans
 where wordVal w = foldl (\acc x -> ((ord $ toLower x) - 96) + acc) 0 w
       triNums = map (\n -> div (n*(n+1)) 2) [1..]
