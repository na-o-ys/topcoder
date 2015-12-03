solve x = a * (x - a)
    where a = x `div` 2
main = getContents >>= putStrLn . show . solve . read
