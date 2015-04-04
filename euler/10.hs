import Data.Set hiding (foldl')
import Data.List (foldl')
import Data.Maybe
seive :: Integer -> Set Integer -> Set Integer
seive p xs
  | p*p > findMax xs = xs
  | otherwise        = seive nextP (xs \\ mults)
    where mults = fromAscList [p*p, (p+1)*p .. findMax xs]
          nextP = fromJust $ lookupGT p xs
primes :: Integer -> [Integer]
primes m = toList $ seive 2 $ fromAscList [2..m]
seive' :: Integer -> Integer -> Set Integer -> Set Integer
seive' n p xs
  | p*p > n   = xs
  | otherwise = seive' n nextP (xs \\ mults)
    where mults = fromAscList [p*p, (p+1)*p .. n]
          nextP = fromJust $ lookupGT p xs
primes' :: Integer -> [Integer]
primes' m = toList $ seive' m 2 $ fromAscList [2..m]
