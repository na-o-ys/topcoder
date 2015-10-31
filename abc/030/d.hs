import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import qualified Data.Vector as V
import qualified Data.Array.IO as A

type VI = V.Vector Int
type AI = A.IOUArray Int Int

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

walk :: VI -> AI -> Int -> Int -> IO (Int, Int)
walk bs vis i c = do
  v <- A.readArray vis i
  case v of
    -1        -> A.writeArray vis i c >> walk bs vis (bs V.! i) (c+1)
    otherwise -> return (v, c-v)

main = do
  [n, a] <- readInts
  k      <- read <$> getLine :: IO Integer
  bs     <- V.fromList . map pred <$> readInts
  vis    <- A.newArray (0, n-1) (-1)

  (x, y) <- walk bs vis (a-1) 0

  print (x, y)
