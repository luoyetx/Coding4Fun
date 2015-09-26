import Data.Char

factorial n = product [1..n]

p20 = sum . map digitToInt . show . factorial $ 100
