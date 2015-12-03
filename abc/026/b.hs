import Control.Applicative
import Data.List

solve (x:xs) v = x ** 2 * pi * v + solve xs (v * (-1))
solve _ _ = 0

main = do
    _ <- getLine
    rs <- reverse . sort . map read . lines <$> getContents
    putStrLn $ show $ solve rs 1
