import Data.List
import Data.Int

main = do
  nums <- readFile "explist.txt"
  let q = map (\(a,b) -> a^b) $ map getNums $ lines nums
  print $ take 1 q
 where getNums x = let (a,b) = span (/=',') x in (read a :: Int64, read (drop 1 $ init b) :: Int64)
