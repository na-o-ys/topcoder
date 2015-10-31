import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

solve _ _ [] _ c = div c 2
solve x y (a:as) bs c = solve y x bs' as (c+1)
  where bs' = dropWhile (< x+a) bs

main = do
  _ <- getLine
  [x, y] <- readInts
  as <- readInts
  bs <- readInts
  print $ solve x y as bs 0
