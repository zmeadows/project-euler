import Euler

isReversible x = all odd $ digitsOf ((read (reverse $ show x) :: Int) + x)

main = print $ (*2) $ length $ filter isReversible [1..500000000]
