import Control.Applicative

main = do
  [n, m] <- map read <$> words <$> getLine
  let a = (fromIntegral m) * 6 :: Double
  let b = (fromIntegral (n `mod` 12) + a / 360) * 30 :: Double
  let v = abs $ a - b
  print $ minimum [v, abs $ 360-v]
