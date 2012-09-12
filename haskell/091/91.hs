answer q = [ (x,x',y,y') | x <- [0..q], x' <- [0..q], y <- [0..q], y' <- [0..q], f x x' y y']
  where f a b c d = ((max a c)^2 + (max d b)^2) == (c-a)^2 + (d-b)^2
                    && ((a,b) /= (0,0))
                    && ((c,d) /= (0,0))

main = print $ answer 2
