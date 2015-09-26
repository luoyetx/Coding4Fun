triples l = [[a, b, c] | a <- [1..l],
                         b <- [a..l],
                         let c = 1000 - a -b,
                         a^2 + b^2 == c^2]

p9 = map product . triples $ 1000
