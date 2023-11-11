import Control.Monad

(~>) = flip (.)

parseInt :: String -> Int
parseInt = read

readInt :: IO Int
readInt = readLn

parseArr :: String -> [Int]
parseArr s = map parseInt $ words s

headSafe :: [a] -> Maybe a
headSafe [] = Nothing
headSafe a = Just (head a)


-- highest powers to lower
polynomSum :: [Int] -> [Int] -> [Int]
polynomSum a b | length a < length b = polynomSum b a 
               | length a > length b = polynomSum a $ (replicate (length a - length b) 0) ++ b
               | otherwise           = zipWith (+) a b

stirlingNum :: Int -> Int -> Int
stirlingNum 0 0 = 1
stirlingNum _ 0 = 0
stirlingNum 0 _ = 0
stirlingNum n k = stirlingNum (n - 1) (k - 1) - (n - 1) * stirlingNum (n - 1) k

downTo :: Int -> Int -> [Int]
downTo b e = [b, b - 1 .. e]
-- completeGraph  -> product [x - n + 1 .. x]
completeGraph :: Int -> [Int]
completeGraph n = map (stirlingNum n) $ downTo n 0


data Graph a = Graph [a] [(a, a)] deriving Show
                           
size :: Graph a -> Int
size (Graph vs _) = length vs
                                                        
linked :: (Eq a) => a -> (a, a) -> Bool   
linked w (v, u) = w == v || w == u

rm :: (Eq a) => Graph a -> a -> Graph a
rm (Graph vs es) v = Graph (filter (v /=) vs) (filter (not . linked v) es)

add :: Eq a => Graph a -> (a, a) -> Graph a
add (Graph vs es) e = Graph vs $ e:es

contract :: Eq a => Graph a -> (a, a) -> Graph a
contract (Graph vs es) (u, v) = 
  let es' = map (sub u v) es in
      rm (Graph vs es') u
    where sub from to (a, b) | from == a = (to, b)
                             | from == b = (a, to)
                             | otherwise = (a, b)

takeNonexistentEdge :: Ord a => Graph a -> Maybe (a, a)
takeNonexistentEdge (Graph vs es) = 
  headSafe $ [(u, v) | u <- vs, v <- vs, u < v && not (elem (u, v) es) && not (elem (v, u) es)]

solve' :: Ord a => Graph a -> [Int]
solve' tree =
  let p = takeNonexistentEdge tree in 
    if p == Nothing then 
      completeGraph $ size tree
    else
      let Just (u, v) = p in
        polynomSum (solve' (add tree (u, v))) $ solve' (contract tree (u, v))


solve :: Ord a => Graph a -> (Int, [Int])
solve tree = let ans = solve' tree in (length ans - 1, ans)

main = getLine >>= parseArr ~> \[n, m] -> replicateM m getLine >>= 
  map ((\[a, b] -> (a, b)) . parseArr) ~> Graph [1..n] ~> solve ~>
  \(n, p) -> print n >> (putStrLn $ unwords $ map show p)

