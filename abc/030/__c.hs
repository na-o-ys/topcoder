import Control.Applicative
import Control.Monad

solve x y as bs c = case as of
    (a:as)    -> solve y x (dropWhile (<x+a) bs) as (c+1)
    otherwise -> c `div` 2

main = do
  [n, [x, y], as, bs] <- replicateM 4 $ map read . words <$> getLine 
  print $ solve x y as bs 0
