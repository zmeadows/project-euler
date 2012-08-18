{-# OPTIONS_GHC -O2 -fno-cse #-}
import Data.List
import Data.Bits

primes :: [Integer]
primes = 2:3:5:7: gaps 11 wheel (join $ roll 11 wheel primes')
  where
    primes' = 11: gaps 13 (tail wheel) (join $ roll 11 wheel primes')
    join ((x:xs): ~(ys:zs:t))  = x : union xs (union ys zs)
                                       `union` join (pairs t)
    pairs ((x:xs):ys:t)        = (x : union xs ys) : pairs t
    gaps k ws@(w:t) cs@(c:u) | k==c  = gaps (k+w) t u
                             | True  = k : gaps (k+w) t cs
    roll k ws@(w:t) ps@(p:u) | k==p  = scanl (\c d->c+p*d) (p*p) ws
                                         : roll (k+w) t u
                             | True  = roll (k+w) t ps
    wheel = 2:4:2:4:6:2:6:4:2:4:6:6:2:6:4:2:6:4:6:8:4:2:4:2:
            4:8:6:4:6:2:4:6:2:6:6:4:2:4:6:2:6:4:2:4:2:10:2:10:wheel

primesFrom a0 = (if a0 <= 2 then [2] else [])
                     ++ (gaps a wh' $ compositesFrom a)
  where
    gaps k ws@(w:t) cs@(c:u) | k==c  = gaps (k+w) t u
                             | True  = k : gaps (k+w) t cs
    (a,wh') = rollFrom (snap (max 3 a0) 3 2)
    snap v origin step = if r==0 then v else v+(step-r)
        where r = rem (v-origin) step  -- NB!: origin <= v !
    rollFrom n = go wheelNums wheel    -- NB!:  else use MOD
        where m  = (n-11) `mod` 210
              go (x:xs) ws@(w:ws') | x < m = go xs ws'
                                   | True  = (n+x-m, ws)  -- (x >= m)
    wheelNums  = scanl (+) 0 wheel
    wheel = 2:4:2:4:6:2:6:4:2:4:6:6:2:6:4:2:6:4:6:8:4:2:4:2:
            4:8:6:4:6:2:4:6:2:6:6:4:2:4:6:2:6:4:2:4:2:10:2:10:wheel
    compositesFrom a =
      foldi union' [] (foldi union [] [multsOf p a | p <- h++[p']]
                       : [multsOf p (p*p) | p <- t])

    union' (x:xs) ys = x : union xs ys
    (h,p':t) = span (< z) primes'                -- p < z => p*p<=a
    z = ceiling $ sqrt $ fromIntegral a + 1      -- p'>=z => p'*p'>a
    primes'  = gaps 11 wheel (foldi union' []
                                   [multsOf p (p*p) | p <- primes''])
    primes'' = 11: gaps 13 (tail wheel) (foldi union' []
                                   [multsOf p (p*p) | p <- primes''])
    multsOf p from = scanl (\c d->c+p*d) (p*x) wh -- (p*)<$>
      where                                       --   scanl (+) x wh
        (x,wh) = rollFrom (snap from p (2*p) `div` p)

    foldi f z (x:t)  = f x $ foldi f z (pairs f t)
    foldi f z []     = z
    pairs f (x:y:t)  = f x y : pairs f t
    pairs f t        = t

fib :: Int -> Integer
fib n = snd . foldl' fib' (1, 0) . dropWhile not $
            [testBit n k | k <- let s = bitSize n in [s-1,s-2..0]]
    where
        fib' (f, g) p
            | p         = (f*(f+2*g), ss)
            | otherwise = (ss, g*(2*f-g))
            where ss = f*f+g*g

find2km :: Integral a => a -> (a,a)
find2km n = f 0 n
    where
        f k m
            | r == 1 = (k,m)
            | otherwise = f (k+1) q
            where (q,r) = quotRem m 2

millerRabinPrimality :: Integer -> Integer -> Bool
millerRabinPrimality n a
    | a <= 1 || a >= n-1 =
        error $ "millerRabinPrimality: a out of range ("
              ++ show a ++ " for "++ show n ++ ")"
    | n < 2 = False
    | even n = False
    | b0 == 1 || b0 == n' = True
    | otherwise = iter (tail b)
    where
        n' = n-1
        (k,m) = find2km n'
        b0 = powMod n a m
        b = take (fromIntegral k) $ iterate (squareMod n) b0
        iter [] = False
        iter (x:xs)
            | x == 1 = False
            | x == n' = True
            | otherwise = iter xs

pow' :: (Num a, Integral b) => (a->a->a) -> (a->a) -> a -> b -> a
pow' _ _ _ 0 = 1
pow' mul sq x' n' = f x' n' 1
    where
        f x n y
            | n == 1 = x `mul` y
            | r == 0 = f x2 q y
            | otherwise = f x2 q (x `mul` y)
            where
                (q,r) = quotRem n 2
                x2 = sq x

mulMod :: Integral a => a -> a -> a -> a
mulMod a b c = (b * c) `mod` a
squareMod :: Integral a => a -> a -> a
squareMod a b = (b * b) `rem` a
powMod :: Integral a => a -> a -> a -> a
powMod m = pow' (mulMod m) (squareMod m)

