corners 1 = [1]
corners x = take 4 $ iterate (+((x-1)*2)) ((last $ (corners (x - 1))) + ((x-1) *2))

main = print (sum $ concat $ map corners [1..501])
