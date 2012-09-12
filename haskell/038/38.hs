import Data.List

isPanNin x = (sort . show) x == "123456789"

findPan x = takeWhile (<987654321) $ map (*x) [1..]
