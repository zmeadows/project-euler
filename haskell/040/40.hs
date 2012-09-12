digList = product $ map (\x -> read [n !! (x-1)] :: Int) $ take 6 $ iterate (*10) 1
  where n = concat $ map show [1..]
