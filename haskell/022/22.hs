import Data.Char
import Data.List
import Names

main = print $ sum $ map (\(a,b) -> a*b) nameValList
  where nameValList = zip [1..] $ map nameValue $ sort names

nameValue x = sum $ map (\x -> let (Just q) = lookup (toLower x) $ zip ['a'..'z'] [1..] in q) x
