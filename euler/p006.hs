p6 =
    let a = sum [1..100]
        b = sum [x*x | x <- [1..100]]
    in a*a - b
