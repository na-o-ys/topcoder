import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

score fs es = 0
dfs fs es t
    | length rem == 0 = trace (show . head $ fs) score fs es
    | t == 0          = maximum . map (\f -> dfs (f:fs) es 1) $ rem
    | t == 1          = minimum . map (\e -> dfs fs (e:es) 0) $ rem
        where rem = [x | x <- [0..8], not (elem x fs), not (elem x es)]

main = do
    putStrLn $ show $ dfs [] [] 0
