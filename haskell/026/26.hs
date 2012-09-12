import Euler

main = print $ maximum $ zip (map recurringCycle [901,903..999]) [901,903..999]
