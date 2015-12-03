import Control.Applicative
import Data.Bits

solve :: [[Int]] -> [Int]
solve (xs:[]) = xs
solve (xs:xss) = xor <$> xs <*> solve xss

ans xs = if elem 0 xs then "hoge" else "fuga"

main = do
  _ <- getLine
  input <- getContents
  putStrLn . ans . solve $ map (map read . words) $ lines input
