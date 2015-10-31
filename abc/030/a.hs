import Control.Applicative

main = do
  [a, b, c, d] <- map read <$> words <$> getLine
  let {
  ans
    | b/a > d/c = "TAKAHASHI"
    | b/a < d/c = "AOKI"
    | otherwise = "DRAW"
  }
  putStrLn ans
