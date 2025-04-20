import Data.Array
 
arr a = listArray (0, length a - 1) a
 
cut k = reverse . dropWhile (==k) . reverse
 
solve :: Int -> Array Int Int -> Array Int Int -> ([Int], [Int])
solve k a c = ( cut 0 $ [0..k-1] >>= return . (\n -> 
                  a!n - sum [ c!i * a!(n - 1 - i) | i <- [0..n-1]])
              , 1:map negate (elems c))

getArr :: IO [Int]
getArr = getLine >>= return . map (read :: String -> Int) . words
 
printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a
 
main = getLine >>= (return . (read :: String -> Int)) >>= \k -> 
        getArr >>= \a ->
        getArr >>= \c ->
          let (p, q) = solve k (arr a) (arr c)
              put a = print (length a - 1) >> printArr a
            in
              put p >> put q
