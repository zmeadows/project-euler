import Data.List

dioX d = (d, (fromJust $ find (\y -> getFloor (d*y*y + 1) == d*y*y + 1) [1..]))

fromJust (Just x) = x

getFloor x = (round $ sqrt q)^2
    where q = fromIntegral x :: Float


getFloor' x = (floor $ sqrt q)
    where q = fromIntegral x :: Float

nonSquare' x = let y = (x - 1) in nonSquare x y

nonSquare x 1 = True
nonSquare x y
    | mod x y == 0 = False
    | otherwise = nonSquare x (y - 1)

answer = map dioX $ filter nonSquare' [2..1000]

primes :: [Integer]
primes = sieve [2..1000]
 where
  sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]


main = mapM (\d -> test d 2) $! filter nonSquare' $! primes

test d 1000000 = print $ "                           FAIL -> d = " ++ (show d)
test d y = do
  let q = (getFloor (d*y*y + 1)) - (d*y*y + 1)
  if q == 0
    then do print $ "x = " ++ (show $ getFloor' (d*y*y + 1)) ++ " y = " ++ (show y) ++ "d = " ++ (show d)
            return ()
    else test d (y+1)


