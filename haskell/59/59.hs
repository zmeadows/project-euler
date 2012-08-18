import Data.Bits (xor)
import Data.Word (Word8)
import Data.List (isInfixOf)
import qualified Data.ByteString.Lazy as B

formatCode :: String -> [Word8]
formatCode s
    | r == "" = [read e :: Word8]
    | otherwise = (read e :: Word8) : formatCode (tail r)
    where (e,r) = break (== ',') s

keys :: [B.ByteString]
keys = [ B.pack [a,b,c] | a <- r, b <- r, c <-r ]
    where r = [32..122] :: [Word8]

isEnglish :: [Word8] -> Bool
isEnglish str = all (>= 32) str && [32,116,104,101,32] `isInfixOf` str

decrypt :: B.ByteString -> B.ByteString -> [Word8]
decrypt code key = B.zipWith xor (B.cycle key) code

main = do
    codes <- fmap (B.pack . formatCode) $ readFile "cipher1.txt"
    B.putStr $ B.pack $ head $ filter isEnglish $ map (decrypt codes) keys
