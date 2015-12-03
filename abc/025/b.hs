import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

dir "East" = 1
dir "West" = -1

format 0 = "0"
format v
    | v < 0     = "West " ++ show (-v)
    | otherwise = "East " ++ show v

move a b [d, x] = (* dir d) . min b . max a $ read x

main = do
    [_, a, b] <- readInts
    putStrLn =<< format . sum . map (move a b) . map words . lines <$> getContents
