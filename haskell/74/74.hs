import Data.Char
import Data.List
import qualified Data.Set as S

facDig x = sum $ map (\q -> product [1..q]) $ map digitToInt $ show x

facList x = (length $ (S.toList . S.fromList ) $ take 60 $ iterate facDig x) == 60

main = print $ length $ filter facList [1..999999]
