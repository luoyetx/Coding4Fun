import Data.List

primes = 2 : filter (null . tail . primeFactor) [3, 5..]

primeFactor n = factor n primes
    where
        factor n (p:ps)
            | p*p > n           = [n]
            | n `mod` p == 0    = p : factor (n `div` p) (p:ps)
            | otherwise         = factor n ps

d n = product [(p * product g - 1) `div` (p - 1) |
                g <- group $ primeFactor n, let p = head g] - n

p21 = sum [n | n <- [2..9999], let m = d n, m > 1, m < 10000, d m == n, d m /= d (d m)]
