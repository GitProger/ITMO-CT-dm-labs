{-# LANGUAGE TupleSections #-}

import Data.Array

modulo = 1000000007
(+.) a b = mod (a + b) modulo
(*.) a b = mod (a * b) modulo
sum' = foldl (+.) 0

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

solve k m c = tail $ elems dp
  where dp = listArray (0, m) $ 1:[sum' [(cb ! (i - j) *. (has ! j)) | j <- [1..i]] | i <- [1..m]]
        cb = listArray (0, m) $ 1:[sum' [(dp ! (i - j) *. (dp  ! j)) | j <- [0..i]] | i <- [1..m]]
        has = accumArray (const id) 0 (0, m) $ map (,1) c -- for e in c: has[e] = 1

main = getArr >>= \[k, m] -> 
       getArr >>= \c -> printArr $ solve k m c
