{-# LANGUAGE FlexibleContexts #-}
{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Control.Applicative
import Debug.Trace
import qualified Data.ByteString.Char8 as BC
import Data.Maybe (fromJust)
import Data.Vector.Mutable

readInts = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine
