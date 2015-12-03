import Control.Applicative

f a b c t = a * t + b * sin (c * t * pi)

solve a b c l h
    | good v    = m
    | v > 100   = solve a b c l m
    | otherwise = solve a b c m h
    where m = (l + h) / 2
          v = f a b c m
          good v = abs (100 - v) < 1e-9

main = do
    [a, b, c] <- map read . words <$> getLine
    putStrLn $ show $ solve a b c 0 110
