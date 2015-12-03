main = do
  input <- getContents
  putStrLn $ show . length . filter (elem 'r') $ lines input
