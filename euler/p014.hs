collatz n
    | n == 1    = 1
    | odd n     = 1 + collatz (3*n + 1)
    | even n    = 1 + collatz (n `div` 2)

p14 = maximum . zip (map collatz [1..m]) $ [1..m]
    where m = 1000000
