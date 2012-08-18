import Euler
import Data.List

products = [ x*y | x <- [100..999], y <- [100..999], isPalindrome (x*y) ]
 where isPalindrome x = (digitsOf x) == (reverse $ digitsOf x)

answer = maximum products

main = print answer
