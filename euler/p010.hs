primes = 2 : filter (null . tail . primeFactor) [3, 5..]

primeFactor n = factor n primes
    where
        factor n (p:ps)
            | p*p > n           = [n]
            | n `mod` p == 0    = p : factor (n `div` p) (p:ps)
            | otherwise         = factor n ps

p10 = sum . takeWhile (<= 2000000) $ primes
