import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

makeList (a:as) (b:bs)
  | a < b     = (0, a) : makeList as (b:bs)
  | otherwise = (1, b) : makeList (a:as) bs
makeList (a:as) bs = (0, a) : makeList as bs
makeList as (b:bs) = (1, b) : makeList as bs
makeList _ _ = []

main = do
  _ <- getLine
  [x, y] <- readInts
  a <- readInts
  b <- readInts
  let {
    f (p, t, c) (q, s)
      | t > s || p /= q = (p, t, c)
      | otherwise       = ((if p == 0 then 1 else 0), s + (if p == 0 then x else y), c+1)
  }
  let (_, _, ans) = foldl f (0, 0, 0) $ makeList a b
  print $ div ans 2
