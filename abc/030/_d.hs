import Control.Applicative
import qualified Data.Map as M

lu = M.findWithDefault 0

walk bp mp i c = case lu i mp of
  0         -> walk bp (M.insert i (c+1) mp) (lu i bp) (c+1)
  otherwise -> ((lu i mp) - 1, c + 1 - (lu i mp))

wk bp s 0 = s
wk bp s i = wk bp (lu s bp) (i-1)

main = do
  [n, a] <- map read <$> words <$> getLine :: IO [Int]
  k <- read <$> getLine :: IO Integer
  bs <- map read <$> words <$> getLine :: IO [Int]
  let bp = M.fromList $ zip [1..n] bs
  let mp = M.fromList $ zip [1..n] (replicate n 0)
  let (x, y) = walk bp mp a 0 :: (Int, Int)
  let {
  kk
    | fromIntegral x >= k = fromIntegral k :: Int
    | otherwise = x + fromIntegral ((k - fromIntegral x) `mod` fromIntegral y) :: Int
  }
  -- print (x, y)
  -- print kk
  print $ wk bp a kk
