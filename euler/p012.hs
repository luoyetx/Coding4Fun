import Data.List

primes = 2 : filter (null . tail . primeFactor) [3, 5..]

primeFactor n = factor n primes
    where
        factor n (p:ps)
            | p*p > n           = [n]
            | n `mod` p == 0    = p : factor (n `div` p) (p:ps)
            | otherwise         = factor n ps

triangles l = head . filter ((>l) . nfactors) . scanl1 (+) $ [1..]
    where nfactors n = product . map ((+1) . length) . group . primeFactor $ n

p12 = triangles 500
