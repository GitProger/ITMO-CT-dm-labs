import Data.Array

modulo = 998244353

powG mul z b p = f b p
  where f b p | p == 0         = z
              | p `mod` 2 == 1 = (b `mul` (f b (p - 1))) 
              | otherwise      = let h = f b (p `div` 2) in h `mul` h
pow = powG (*.) 1
sqr b = pow b 2
inv n = pow n (modulo - 2)

zpn z f (p:ps) (q:qs) = f p q : zpn z f ps qs
zpn z f []     (q:qs) = f z q : zpn z f [] qs
zpn z f (p:ps) []     = f p z : zpn z f ps []
zpn z f []     []     = []

sgnpow n = if odd n then -1 else 1

add p q = zpn 0 (+.) p q
mul p q = foldr1 (\a b -> zpn 0 (+.) a (0:b)) $ map (\c -> map (c*.) p) q 
mulcnst c p = map (c*) p
neg = mulcnst (-1)

apply p t = foldr (\c acc -> c + t * acc) 0 p


(!?) a i = if i >= 0 && i < length a then a ! i else 0

sum' = foldl (+.) 0

divide :: [Int] -> [Int] -> [Int]
divide p q = elems coefs
  where m = length p - 1
        p' = listArray (0, m) p
        q' = listArray (0, length q - 1) q
        coefs = listArray (0, m)
                [(p' !? i) -. (sum' [(coefs ! j) *. (q' !? (i - j))
                                        | j <- [0..i - 1]])
                | i <- [0..m]]

a +. b = mod (a + b) modulo
a -. b = mod (a - b) modulo
a *. b = mod (a * b) modulo
a /. b = a *. (inv b)
infixl 6 +. 
infixl 6 -. 
infixl 7 *. 
infixl 7 /. 

binoms :: Int -> Array Int (Array Int Int) 
binoms n = listArray (0, n) $ map (\a -> listArray (0, min n $ length a - 1) a) bs 
  where bs = iterate (\prev -> zipWith (+.) (prev++[0]) (0:prev)) [1]

facts n = listArray (0, n) $ scanl (*.) 1 [1..]
catalan = zipWith (\c n -> c *. (4 * n - 2) /. (n + 1)) (1:catalan) [1..]
-------------------------------------------------------------------------------

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

solve :: Int -> Int -> [Int]
solve k n = let p = [(sgnpow i) *. (binom (k - 1 - i - 1) i) | i <- [0..k-2]] ++ off
                q = [(sgnpow i) *. (binom (k - 1 - i    ) i) | i <- [0..k-2]] ++ off 
                off = replicate ((max (n - k) 0) + 2) 0
                facs = facts k 
                binom n k = (facs !? n) /. ((facs ! k) *. (facs !? (n - k)))
                -- gen function is p/q
              in take n $ divide p q

main = getArr >>= \[k, n] -> mapM_ print $ solve k n
