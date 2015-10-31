import Control.Applicative
import Control.Monad
import qualified Data.Array.IO as A

type Arr = A.IOUArray Int Int
toPair (a:b:_) = (a, b)

newArray :: Int -> IO Arr
newArray n = A.newArray (1, n+1) 0

updateArr :: Arr -> Int -> Int -> IO ()
updateArr arr s t = do
  A.readArray arr s     >>= A.writeArray arr s     . (+1)
  A.readArray arr (t+1) >>= A.writeArray arr (t+1) . (+(-1))

imos :: Arr -> Int -> IO ()
imos arr n = do
  forM_ [1..n] $ \i -> do
    v <- A.readArray arr i
    w <- A.readArray arr (i+1)
    A.writeArray arr (i+1) (v+w)

isGood :: Arr -> Int -> Int -> IO (Bool)
isGood arr s t = foldM f True [s..t]
  where f ans i = A.readArray arr i >>= return . (ans&&) . (>1)

main = do
  [n, m] <- map read <$> words <$> getLine
  sts <- replicateM m (toPair . map read <$> words <$> getLine)
  arr <- newArray n

  forM_ sts $ uncurry $ updateArr arr
  imos arr n

  let isGood' (_, (s, t)) = isGood arr s t
  ans <- filterM isGood' $ zip [1..] sts
  print $ length ans
  sequence_ $ print . fst <$> ans
