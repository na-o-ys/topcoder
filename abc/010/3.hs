{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

dist (x1, y1) (x2, y2) = sqrt $ x' * x' + y' * y'
    where
        x' = x1 - x2
        y' = y1 - y2

canMove xa ya xb yb t v ([x, y] :: [Double])
    = dist (xa, ya) (x, y) + dist (xb, yb) (x, y) <= t * v

main = do
    [xa, ya, xb, yb, t, v] <- map fromIntegral <$> readInts
    [n] <- readInts
    ans <- replicateM n $ canMove xa ya xb yb t v <$> map fromIntegral <$> readInts
    putStrLn $ if or ans then "YES" else "NO"
