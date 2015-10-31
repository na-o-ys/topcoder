{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
import Control.Applicative
import Control.Monad
import qualified Data.Map as M

initMp n = M.fromList $ zip [1..n] (replicate n 0)

createMap :: M.Map Int Int -> [[Int]] -> M.Map Int Int
createMap mp = foldl ins mp
  where ins mp' [s, t] = inc s . dec (t+1) $ mp'
        inc = M.adjust (+1)
        dec = M.adjust (+(-1))

imos v i mp = case M.lookup i mp of
  Just u    -> imos w (i+1) $ M.adjust (+v) i mp
    where w = u + v
  otherwise -> mp

isGood mp s t = (==(t-s+1)) . length . filter good $ [s..t]
  where good i = (>1) . M.findWithDefault 0 i $ mp

main = do
  [n, m] <- map read <$> words <$> getLine
  sts <- replicateM m (map read <$> words <$> getLine)
  let mp  = createMap (initMp n) sts
  let mp' = imos 0 1 mp
  let good (i, [s, t]) = isGood mp' s t
  let ans = filter good $ zip [1..] sts
  putStrLn . show . length $ ans
  sequence_ $ putStrLn <$> show <$> fst <$> ans
