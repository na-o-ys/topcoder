import Control.Monad

main = do
  n <- readLn
  sequence_ $ map putStrLn $ replicateM n ['a', 'b', 'c']
