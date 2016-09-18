import Debug.Trace
import Control.Applicative

solve c [] = []
solve c [x] = [c + x]
solve c (x:xs) = ((+v) <$> solve 0 xs) ++ solve (v * 10) xs 
    where v = x + c

main = getLine >>= print . sum . solve 0 . map (read . pure)
