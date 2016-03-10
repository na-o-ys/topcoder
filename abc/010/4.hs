{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as MV

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

main = do
    vec <- MV.replicate 3 (0 :: Int)
    let l = V.toList $ V.freeze vec
    print l
