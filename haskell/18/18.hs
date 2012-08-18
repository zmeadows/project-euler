import Data.Array.Unboxed

mT r r' = r // (map getMax $ assocs r)
 where mL = snd $ bounds r
       getMax (x,y)
         | x == 1 = (1,((r' ! 1) + (r ! 1)))
         | x == mL = (mL,((r' ! (mL - 1)) + (r ! mL)))
         | otherwise  = (x, max ((r' ! x) + (r ! x)) ((r' ! (x - 1)) + (r ! x)))

main = do
 tree <- readFile "tri.txt"
 let tree' = map (\q -> map (\r -> read r :: Int) q) $ map words $ lines tree
     tree'' = map (\q -> listArray (1, length q) q :: UArray Int Int) tree'
     tree''' = foldl1 (\r' r -> mT r r') tree''
 print tree'''

