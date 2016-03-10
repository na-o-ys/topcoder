import Control.Applicative
import Control.Monad
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

solve x y as bs c = case as of
    (a:as)    -> solve y x (dropWhile (<x+a) bs) as (c+1)
    otherwise -> c `div` 2

main = do
  _ <- getLine
  [[x, y], as, bs] <- replicateM 3 readInts
  print $ solve x y as bs 0
