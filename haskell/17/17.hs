import Euler

single x
  | x == 1 = "one"
  | x == 2 = "two"
  | x == 3 = "three"
  | x == 4 = "four"
  | x == 5 = "five"
  | x == 6 = "six"
  | x == 7 = "seven"
  | x == 8 = "eight"
  | x == 9 = "nine"

tens x
  | x == 2 = "twenty"
  | x == 3 = "thirty"
  | x == 4 = "forty"
  | x == 5 = "fifty"
  | x == 6 = "sixty"
  | x == 7 = "seventy"
  | x == 8 = "eighty"
  | x == 9 = "ninety"

name x
  | q == 1 = single x
  | q == 2 = nameTen $ digitsOf x
  | q == 3 = nameHun $ digitsOf x
  | otherwise = "onethousand"
 where q = digitsIn x

nameHun x
  | (x !! 1 == 0) && (x !! 2 == 0) = (single $ head x) ++ "hundred"
  | (x !! 1 == 0) = (single $ head x) ++ "hundredand" ++ (single $ last x)
  | otherwise = (single $ head x) ++ "hundredand" ++ (nameTen $ tail x)

nameTen x
  | last x == 0 && head x == 1 = "ten"
  | head x == 1 = teens x
  | last x == 0 = tens $ head x
  | otherwise = (tens $ head x) ++ (single $ last x)

teens x
  | q == 1 = "eleven"
  | q == 2 = "twelve"
  | q == 3 = "thirteen"
  | q == 4 = "fourteen"
  | q == 5 = "fifteen"
  | q == 6 = "sixteen"
  | q == 7 = "seventeen"
  | q == 8 = "eighteen"
  | q == 9 = "nineteen"
 where q = last x

main = print $ length $ concat $ map name [1..1000]
