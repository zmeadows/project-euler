answer = sqSum - sumSq
  where sumSq = sum $ map (^2) [1..100]
        sqSum = (^2) $ sum [1..100]

main = print answer
