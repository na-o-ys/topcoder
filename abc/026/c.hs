import Control.Applicative
import Data.List

solve bs n = val $ map (solve bs) $ elemIndices n bs where
    val [] = 1
    val bs = maximum bs + minimum bs + 1

main = do
    _  <- getLine
    bs <- map (pred . read) . lines <$> getContents
    print $ solve (-1:bs) 0
