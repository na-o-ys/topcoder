primes [] = []
primes (x:xs) = x : primes [y | y <- xs, y `mod` x /= 0]
main = putStrLn $ show $ take 100 $ primes [2..1000]
