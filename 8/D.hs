import Data.Array
import Data.Ratio
import Text.Printf
-- Rational --> Ratio Integer
pow b p | p == 0         = 1
        | p `mod` 2 == 1 = (b * (pow b (p - 1))) 
        | otherwise      = ((pow b (p `div` 2)) ^ 2)

-- A(t)=P(t)/(1-rt)^(k+1)
-- \sum_{n=0} a_n t^n = P(t) * (series x_0=0: 1/(1-rt)^(k+1))
-- = P(t) \sum_{m=0} C_{m+k}^k (rt)^m
-- = \sum_{i=0}^k p_i t^i * \sum_{m=0}^{\infty} (m + k; k) (rt)^m
-- a_n = \sum_{i <= k; i + m = n} p_i (m + k; k) r^m    # use only where t^(i+m) == t^n
-- m := n - i; m >= 0 => i <= n
-- a_n = \sum_{i=0}^min(k,n) p_i (n + k - i; k) r^(n-i)
-- a_n = r^n \sum_{i=0}^min(k,n) p_i (n + k - i; k) r^-i
-- f(n) = \sum_{i=0}^{min(k, n)} p_i (n + k - i; k) / r^i
-- Известно, что для достаточно больших n => assuming n > k
-- f(n) = \sum_{i=0}^k p_i (n + k - i; k) / r^i
-- f(n) = \sum_{i=0}^k p_i (n+k-i)!/(n-i)!/k! / r^i
-- f(n) = \sum_{i=0}^k p_i (П n-i+1..n-i+k) / (k! r^i)
-- f(n) = \sum_{i=0}^k (p_i / k! r^i) П (n-(i-k))..(n-(i-1))

ix a i = if i >= 0 then a !! i else 0

cof k = map (\i -> -- index for p_i
              foldl
                (\f_i j -> map (\l -> (f_i!!l) * (j-i) + (f_i `ix` (l - 1))) [0..k])
                (1:(replicate k 0))
                [k,k-1..1]
            ) [0..k]

solve :: Int -> Int -> [Int] -> [Ratio Int]
solve r k p = 
              [ sum [ (f !! i !! j) * (p!!i) * (pow r (k - i)) 
                    | i <- [0..k] ] % (pow r k) / factK
              | j <- [0..k] ]
            where f = cof k
                  factK = product $ take k [1..] -- fromIntegral
            --  foldl1 (zipWith (+)) [
            --      map (\j -> (f !! i !! j) * (p!!i) * (pow r (k - i)) % (pow r k) / factK) 
            --          [0..k]
            --  | i <- [0..k]]
            --where f = cof k
            --      factK = product $ take k [1..] -- fromIntegral

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getArr >>= \[r, k] -> 
       getArr >>= \p ->
          let res = solve r k p in
            mapM_ (\r -> printf "%d/%d " (numerator r) (denominator r))
                  res
              >> putStrLn ""
