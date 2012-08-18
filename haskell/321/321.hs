import Data.Bits
import Data.Char
import Numeric

data Row = Row { reds  :: Integer
               , blues :: Integer
               , empty :: Integer
               } deriving (Show, Eq)

createRow n = Row { reds = sum $ map (2^) [2*n,2*n-1..n+1]
                  , blues = sum $ map (2^) [0..n-1]
                  , empty = 2^n }

printRow (Row r b e) = let rr = [toB r,toB b,toB e] in
    printRow' (rr !! 0) (rr !! 1)  (rr !! 2)  (maximum $ map length rr)
  where toB n = showIntAtBase 2 intToDigit n ""

printRow' r b e maxL =
    zipWith3 pick (repOne 'R' $ fixL r) (repOne '*' $ fixL e) (repOne 'B' $ fixL b)
        where repOne w s = map (\c -> if c == '1' then w else c) s
              fixL s = replicate (maxL - length s) '0' ++ s
              pick a b c
                | a /= '0' = a
                | b /= '0' = b
                | otherwise = c


slideRight (Row r b e)
    | (r .&. (shiftL e 1)) /= 0 =
        Row ((r `xor` e) `xor` (shiftL e 1)) b (shiftL e 1)
    | otherwise = Row r ((b `xor` e) `xor` (shiftL e 1)) (shiftL e 1)

slideLeft (Row r b e)
    |  (b .&. (shiftR e 1)) /= 0 =
        Row r ((b `xor` e) `xor` (shiftR e 1)) (shiftR e 1)
    | otherwise = Row ((r `xor` e) `xor` (shiftR e 1)) b (shiftR e 1)
