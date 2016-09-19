{-# LANGUAGE ScopedTypeVariables #-}
import Control.Applicative
import Data.List
import Debug.Trace

dbg v = traceShow v v

points h w [a, b] = (,) <$> range h a <*> range w b
    where range max = filter (cond max) . ((+) <$> [-2..0] <*>) . pure
          cond max  = (&&) <$> (>= 0) <*> (<= max - 3)

frequencies :: Ord a => [a] -> [(a, Int)]
frequencies = map keyAndLen . group . sort
    where keyAndLen grp = (head grp, length grp)

-- [(0,0), (0,0), (1,1), (1,1), (1, 2)]
-- [2, 2, 1]
-- [(1, 1), (2, 2)]
solve h w ls = freqs2
    where ps       = dbg $ ls >>= points h w
          freqs    = dbg $ frequencies $ ps
          freqs2   = dbg $ frequencies . filter (<= 9) . map snd $ freqs
          mp       = 

main = do
    [h, w, _] :: [Int] <- map read . words <$> getLine
    ls :: [[Int]]      <- map (map (pred . read) . words) . lines <$> getContents
    print $ solve h w ls
