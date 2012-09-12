import Euler

main = print $ maximum $ map (\n -> ((fl n)/(fl $ phi n),n)) [1..1000000]
  where fl x = fromIntegral x :: Float
