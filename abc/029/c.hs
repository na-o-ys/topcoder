import Control.Monad

main = do
  n <- readLn
  putStr . unlines . replicateM n $ "abc"
