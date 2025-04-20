import Data.Array
-- http://e-maxx.ru/algo/reverse_element fermat thorem

modulo = 998244353

binpow b p m | p == 0         = 1
             | p `mod` 2 == 1 = (b * (binpow b (p - 1) m)) `mod` m  
             | otherwise      = ((binpow b (p `div` 2) m) ^ 2) `mod` m
inv n = binpow n (modulo - 2) modulo
pow b p = binpow b p modulo
sqr b = pow b 2

facts = listArray (0, 1000) $ scanl (*.) 1 [1..]

zpn z f (p:ps) (q:qs) = f p q : zpn z f ps qs
zpn z f []     (q:qs) = f z q : zpn z f [] qs
zpn z f (p:ps) []     = f p z : zpn z f ps []
zpn z f []     []     = []

a +. b = mod (a + b) modulo
a -. b = mod (a - b) modulo
a *. b = mod (a * b) modulo
a /. b = a *. (inv b) -- (binpow b (modulo - 2) modulo) 
infixl 6 +. 
infixl 6 -. 
infixl 7 *. 
infixl 7 /. 


sgnpow n = if odd n then -1 else 1
add p q = zpn 0 (+.) p q
mul p q = foldr1 (\a b -> zpn 0 (+.) a (0:b)) $ map (\c -> map (c*.) p) q 

-- better just substitue P(t) to x instead of proper differentiation
getSeries :: (Int -> Int) -> Int -> [Int] -> [Int]
getSeries coeff m p = take m cs 
  where cs = foldl1 add $ zipWith (\k pk -> map (\x -> x *. (coeff k)) pk) [0..m-1]
                        $ iterate (mul p)
                        $ 1 : (repeat 0)
--  where cs = foldl1 add $ zipWith (\k pk -> map (\x -> x *. (coeff k)) pk) [0..m-1]
--                        $ map (take m) 
--                        $ iterate (mul p)
--                        $ 1 : (replicate (m - 1) 0)

-- generating function of calatan numbers
-- Catalan(n)/2^(2n+1)  /   denominator of binomial(2n,n)/4^n
-- binomial(2n,n)/(n+1)   /    denominator of binomial(2n,n)/4^n
-- (2n)!/(n!(n+1)!)       /    (2 * 4 ^ n); n = k - 1
-- (2n)!/n!/n!            /    2^(2n+1)*(n+1)
sqrts = getSeries (\k -> if k == 0 then 1 else
                    (sgnpow (k - 1)) *. (facts ! (2 * (k - 1)))
                      /.
                    (2 * k *. (sqr (facts ! (k - 1))) *. (pow 4 (k - 1))))
exps  = getSeries (\k -> inv (facts ! k))
logs  = getSeries (\k -> if k == 0 then 0 else (sgnpow (k + 1)) /. k)

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getArr >>= \[n, m] -> 
       getArr >>= \p ->
          mapM_ printArr [sqrts m p, exps m p, logs m p]
