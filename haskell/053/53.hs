fac x = product [1..x]
comb n r = (fac n) `div` ((fac r)*((fac (n-r))))
combs n = map (comb n) [1..n]
answer = length $ filter (>1000000) $ concat $ map combs [1..100]

main = print answer
