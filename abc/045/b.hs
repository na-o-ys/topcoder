import Control.Applicative
import Debug.Trace
import Data.Char (ord)
 
solve (a:as) bs cs 0 = solve as bs cs a
solve as (b:bs) cs 1 = solve as bs cs b
solve as bs (c:cs) 2 = solve as bs cs c
solve _ _ _ n = ["A", "B", "C"] !! n
 
charToInt c = ord c - ord 'a'
 
main = do
    [a, b, c] <- map (map charToInt) <$> lines <$> getContents
    putStrLn $ solve a b c 0
