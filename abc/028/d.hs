import Control.Applicative
import Text.Printf

solve :: Double -> Double -> Double
solve n k = (a + b + c) / (n ^ 3)
  where a = 1
        b = 3 * (n - 1)
        c = 6 * (k - 1) * (n - k)

main = do
  [n, k] <- map read <$> words <$> getLine
  printf "%.12f\n" $ solve n k
