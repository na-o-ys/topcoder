import Control.Applicative
import Debug.Trace
import Data.List

val [] = 1
val bs = maximum bs + minimum bs + 1

solve bs n = val $ map (solve bs) $ map succ $ elemIndices n bs

main = do
    _ <- getLine
    bs <- map (pred . read) . lines <$> getContents
    putStrLn $ show $ solve bs 0
