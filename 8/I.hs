import Data.Array
import Debug.Trace (trace, traceId)
-- http://neerc.ifmo.ru/wiki/index.php?title=%D0%91%D1%8B%D1%81%D1%82%D1%80%D0%BE%D0%B5_%D0%B2%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D1%87%D0%BB%D0%B5%D0%BD%D0%BE%D0%B2_%D0%BB%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D0%BE%D0%B9_%D1%80%D0%B5%D0%BA%D1%83%D1%80%D1%80%D0%B5%D0%BD%D1%82%D0%BD%D0%BE%D0%B9_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8

modulo = 104857601

a +. b = mod (a + b) modulo
a -. b = mod (a - b) modulo
infixl 6 +., -.

sum' = foldl (+.) 0
arr a = listArray (0, length a - 1) a

getAns :: Int -> Int -> Array Int Int -> Array Int Int -> Int 
getAns k n a q = go n a q
  where go n a q | n < k     = a ! n
                 | otherwise = go (n `div` 2) (filt n $ dupe a q) (rq q)
        dupe a q = a'
             where a' = arr [if i < k then a ! i 
                                      else 0 -. sum' [(q ! j) * (a' ! (i - j)) | j <- [1..k]]
                            | i <- [0..2 * k - 1]]

        filt n a = arr [a ! i | i <- [s, s + 2 .. snd (bounds a)]]
          where s = n `mod` 2

        rq :: Array Int Int -> Array Int Int -- length q = k + 1
        rq q = arr [cof i | i <- [0,2..2*k]]
          where nq = arr [if even i then q ! i else modulo - q ! i | i <- [0..k]]
                cof i = foldl (\acc j -> 
                  if j <= k && (i - j) <= k 
                    then (acc + (q ! j) * nq ! (i - j)) `mod` modulo 
                    else acc) 0 [0..i]

solve k n a c = getAns k (n - 1) (arr (a ++ replicate k 0)) (arr (1:map (modulo-) c))

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getArr >>= \[k, n] -> 
       getArr >>= \a -> 
       getArr >>= \c -> print $ solve k n a c
