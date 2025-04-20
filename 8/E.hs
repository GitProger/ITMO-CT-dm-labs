import Data.Array
-- Rational --> Ratio Integer
powG mul z b p = f b p
  where f b p | p == 0         = z
              | p `mod` 2 == 1 = (b `mul` (f b (p - 1))) 
              | otherwise      = let h = f b (p `div` 2) in h `mul` h
pow = powG (*) 1

zpn z f (p:ps) (q:qs) = f p q : zpn z f ps qs
zpn z f []     (q:qs) = f z q : zpn z f [] qs
zpn z f (p:ps) []     = f p z : zpn z f ps []
zpn z f []     []     = []

add p q = zpn 0 (+) p q
mul p q = foldr1 (\a b -> zpn 0 (+) a (0:b)) $ map (\c -> map (c*) p) q 
mulcnst c p = map (c*) p
neg = mulcnst (-1)

apply p t = foldr (\c acc -> c + t * acc) 0 p
--          -- sum $ zipWith (*) p $ iterate (*t) 1
--          -- sum $ zipWith (\p_i i -> p_i * (pow t i)) p [0..length p - 1]

cut k = reverse . dropWhile (==k) . reverse

solve :: Int -> Int -> [Int] -> ([Int], [Int])
solve r d p = (take (d + 1) $ a `mul` q, q)
  where q = powG mul [1] [1, -r] (d + 1) -- (1-rt)^(d+1) from previous task
        a = map (\i -> (apply p i) * (pow r i)) [0..d] 

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getArr >>= \[r] -> 
       getArr >>= \[d] ->
       getArr >>= \p' ->
          let (p, q) = solve r d p'
              put a = print (length a - 1) >> printArr a
            in
              put p >> put q
