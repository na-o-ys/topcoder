{-# LANGUAGE ScopedTypeVariables #-}
import Control.Applicative

solve xs n
    | avg * n == s = solve' xs avg 0
    | otherwise    = -1
    where avg = s `div` n
          s   = sum xs
solve' (x:xs) avg r = v + solve' xs avg (crr - avg)
    where crr = x + r
          v
              | crr == avg = 0
              | otherwise  = 1

solve' _ _ _ = 0
main = do
    n  <- read <$> getLine
    as <- map read <$> words <$> getLine
    putStrLn . show $ solve as n
