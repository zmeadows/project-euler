import qualified Data.Set as S

merge :: (Ord a) => [a] -> [a] -> [a]
merge xs@(x:xt) ys@(y:yt) =
  case compare x y of
    LT -> x : (merge xt ys)
    EQ -> x : (merge xt yt)
    GT -> y : (merge xs yt)

diff :: (Ord a) => [a] -> [a] -> [a]
diff xs@(x:xt) ys@(y:yt) =
  case compare x y of
    LT -> x : (diff xt ys)
    EQ -> diff xt yt
    GT -> diff xs yt

primes, nonprimes :: [Integer]
primes    = [2, 3, 5] ++ (diff [7, 9 ..] nonprimes)
nonprimes = foldr1 f . map g . tail $ primes
  where
    f (x:xt) ys = x : (merge xt ys)
    g p         = [ n * p | n <- [p, p + 2 ..]]

answer = [ a+b+c | a <- squares, b <- cubes, c <- fourths, a+b+c < 50000000]
            where squares = takeWhile ( < 50000000 ) $ map (\x -> x*x) primes
                  cubes   = takeWhile ( < 50000000 ) $ map (\x -> x*x*x) primes
                  fourths = takeWhile ( < 50000000 ) $ map (\x -> x*x*x*x) primes

nub' = S.toList . S.fromList

main = print $ length $ seq answer (nub' answer)
