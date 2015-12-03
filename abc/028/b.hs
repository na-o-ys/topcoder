charCount :: Char -> [Char] -> Int
charCount a = length . filter (==a)
seqCharCount = sequence $ map charCount "ABCDEF"
main = getLine >>= putStrLn . unwords . map show . seqCharCount
