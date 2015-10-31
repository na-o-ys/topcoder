import Data.Array.ST
import Control.Monad
import Control.Monad.ST
import Data.STRef
import Data.Char

pow :: Int -> Int -> Int
pow a b = runST $ do    -- ST モナド
  v <- newSTRef 1       -- v :: STRef s Int
  forM_ [1..b] $ \i ->
    modifySTRef v (* a)
  readSTRef v           -- STRef s Int -> ST s Int
                        -- 参照値から固定値への変更


kk = runST $ do
  a <- newArray ((1,1), (9,9)) 0
         :: ST s (STUArray s (Int, Int) Int)
  forM_ [(x, y) | x <- [1..9], y <- [1..9]] $ \(i,j) ->
    writeArray a (i,j) (i * j)
  getElems a

-- kk = newArray ((0,0), (9,9)) [x * y | x <- [0..9], y <- [0..9]]

strToInts :: [Char] -> [Int]
strToInts = map $ \c -> ord c - ord '0'

solve :: Int -> Int -> [[Int]] -> Int
solve n m arr = 1

main = do
  n <- readLn
  m <- readLn
  lines <- replicateM n getLine
  print $ solve n m $ map strToInts lines
