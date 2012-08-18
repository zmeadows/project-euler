import Data.List
qqq = [ [a,b,c,d,e,f,g] | a <- [17..21], b <- [28..32], c <- [35..39], d <- [36..40], e <- [37..41], f <- [39..43], g <- [41..45]]

main = print $ filter (\x -> length (map sum (subsequences x)) == length (nub (map sum (subsequences x)))) qqq
