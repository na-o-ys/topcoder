import Data.List

solve [a,b,c]
    | b == c    = a
    | otherwise = c

main = getLine >>= putStrLn . solve . sort . words
