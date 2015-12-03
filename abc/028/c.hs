import Control.Monad
import Data.List

tripleSums :: [Int] -> [Int]
tripleSums xs = nub . reverse . sort . map sum $ triples
  where isUniq xs = nub xs == xs
        triples = filter isUniq $ replicateM 3 xs

main = do
  line <- getLine
  let nums = map read . words $ line
  putStrLn . show $ (tripleSums nums) !! 2
