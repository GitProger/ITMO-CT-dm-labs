import Data.Array

modulo = 998244353
limit = 1000

a +. b = mod (a + b) modulo
a -. b = mod (a - b) modulo
a *. b = mod (a * b) modulo
infixl 7 *. 


-- assuming q_0 = 1
-- formula: c_k = p_k - \sum_{i=1}^{min(k, m)} q_i c_{k-i} for k in [0..]
--
-- for k in range(1000):
--   r = p[k] if k <= n else 0
--   for i in range(1, min(k, m - 1)):
--     r += q[i] * c[k - i]
--   c.append(r)
recurDivision :: Int -> Int -> [Int] -> [Int] -> ([Int])
recurDivision n m p q = elems coefs
  where
    pArr = listArray (0, length p - 1) p
    qArr = listArray (1, length q - 1) (tail q) -- q0 = 1
    coefs = listArray (0, limit - 1) [c k | k <- [0..limit - 1]]
    c k = (if k <= n then pArr ! k else 0)
           -. (foldl (+.) 0 [qArr ! i *. coefs ! (k - i) | i <- [1..min k m]]) -- sum

solve :: Int -> Int -> [Int] -> [Int] -> (Int, [Int], Int, [Int], [Int])
solve n m p q = ( max n m
                , zpn 0 (+.) p q
                , n + m 
                , foldr1 (\a b -> zpn 0 (+.) a (0:b)) $ map (\c -> map (c*.) p) q 
                , recurDivision n m p q ) 
  where zpn z f (p:ps) (q:qs) = f p q : zpn z f ps qs
        zpn z f []     (q:qs) = f z q : zpn z f [] qs
        zpn z f (p:ps) []     = f p z : zpn z f ps []
        zpn z f []     []     = []

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getArr >>= \[n, m] -> 
       getArr >>= \p -> 
       getArr >>= \q ->
        let (ps, cs, pm, cm, cd) = solve n m p q in do 
          print ps
          printArr cs
          print pm
          printArr cm
          printArr cd
