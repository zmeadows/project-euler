import Data.List
import Data.Char

type T = ([Int],Int,[Int])
type E = (Int,Int,Int)

main = do
  keylog <- fmap (nub . lines) $ readFile "keylog.txt"
  return keylog

nullset :: [T]
nullset = fmap (\n -> ([],n,[])) [0..9]

bn i (b,n,a) = (i++b,n,a)
an i (b,n,a) = (b,n,i++a)

readE :: String -> E
readE = (\[a,b,c] -> (a,b,c)) . map digitToInt

editT 

crack ts ((a1,a2,a3):es) = 
