{-# LANGUAGE ScopedTypeVariables #-}
import Control.Applicative
import Data.List
import Debug.Trace

x -: f = f x

points [a, b] = (,) <$> range a <*> range b
    where range = filter (>= 0) . ((+) <$> [-2..0] <*>) . pure

--solve ls = sort . map length . group . sort $ points =<< ls
solve ls = (ls >>= points) -: sort -: group -: map length -: sort

main = do
    [h, w, _] :: [Int] <- map read . words <$> getLine
    ls :: [[Int]]      <- map (map read . words) . lines <$> getContents
    print $ solve ls
