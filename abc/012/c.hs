import Control.Monad

solve :: Int -> [String]
solve n = map show' $ filter good pair
  where pair = replicateM 2 [1..9]
        good [x, y] = x*y == 2025 - n
        show' [x, y] = show x ++ " x " ++ show y

main = do
  n <- readLn
  sequence_ $ map putStrLn $ solve n
