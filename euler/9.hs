import Control.Monad
tri :: Integer -> [[Integer]]
tri m = [[a,b,c] |
        a <- [1..m], b <- [a..m], c <- [m-a-b],
        c > 0,
        a^2 + b^2 == c^2]
prd :: Integer -> [Integer]
prd = map product . tri
