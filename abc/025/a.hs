import Control.Applicative

main = do
    s <- getLine
    n <- pred . read <$> getLine
    putStrLn [s !! (n `div` 5), s !! (n `mod` 5)]
