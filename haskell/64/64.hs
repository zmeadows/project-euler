import Data.List

--sqrtPeriod n = sqrtPeriod' 1 n [n]
 --   where sqrtPeriod' t b p = let b' = b - (last $ takeWhile (\x -> x - b <= (floor $ sqrt n)) $ map (*(div (n - b*b) t)) [1..]) in
  --              sqrtPeriod' (div (n - b*b) t) b' ((div (b' + b) (div (n - b*b) t)) : p)

sqrtPeriod :: Int -> Int -> Int -> Int -> [Int] -> IO Int
sqrtPeriod n nf t b p = do
  let t' = div (n - b*b) t
      b' = (last $ takeWhile (\x -> x - b <= nf) $ map (*t') [1..]) - b
      p' = [(div (b' + b) t')] ++ p
      (l,r) = splitAt (div (length p') 2) p'
  if (t' == t && b' == b)
    then return 1
    else if l == r && (length (nub p') > 1)
            then return (div (length p') 2)
            else sqrtPeriod n nf t' b' p'

sper n = sqrtPeriod n fn 1 fn []
    where fn = truncate $ sqrt (fromIntegral n :: Float)

main = do
    a <- mapM sper $ [2..10000] \\ (map (\x -> x*x) [2..100])
    print $ length $ filter odd a
