import Text.ParserCombinators.ReadP

data Obj = B | L Obj | S Obj | P Obj Obj deriving Show

---- Parser -------------------------------------------------------------------
parseChar :: Char -> ReadP ()
parseChar c = skipSpaces >> char c >> skipSpaces

parseB :: ReadP Obj 
parseB = parseChar 'B' >> return B

parseLS :: Char -> (Obj -> Obj) -> ReadP Obj 
parseLS c f = do 
  parseChar c >> parseChar '(' -- c = 'L' -> multiple result [(res1, ""), (res2, "") ...]
  obj <- parseObj
  parseChar ')'
  return $ f obj

parseL = parseLS 'L' L
parseS = parseLS 'S' S

parseP :: ReadP Obj
parseP = do 
  parseChar 'P' >> parseChar '('
  o1 <- parseObj
  parseChar ','
  o2 <- parseObj
  parseChar ')'
  return $ P o1 o2

parseObj :: ReadP Obj
parseObj = choice [parseB, parseL, parseS, parseP] --(parseB <|> parseL <|> parseS <|> parseP)
  
parse :: String -> Maybe Obj
parse s = case readP_to_S parseObj s of 
  [(res, "")] -> Just res 
  _           -> Nothing

---- /Parser ------------------------------------------------------------------
---- Solution -----------------------------------------------------------------

fac n = f n 1 where f 0 a = a
                    f n a = f (n - 1) (a * n)
binom n k = (fac n) `div` (fac k) `div` (fac $ n - k)

solve :: Int -> Obj -> [Int]
solve n B = 0:1:(replicate (n - 1) 0) -- weight of unit is 1, other variants are impossible

-- S(L(B)) https://oeis.org/search?q=1+1+2+3+5+7+11
-- S(X): for every x from X: we can take 1..m copies of x
--                 they result as 1+t^k+t^2k+... = 1/(1-t^k)
--                 all choices are indepenant (unline in L) so multiply all 1/(1-t^k)^weight(x)
-- so gen function: S_x(t) = П_{k=1}^inf 1/(1-t^k)^a_k
-- ln S(t) = \sum_{k=1}^inf a_k ln(1/(1-t^k))
-- ln(1/(1-t^k)) = [t^k := r] = \sum_{m=1}^inf t^(km) / m
-- ln S(t) = \sum_{n=1}^inf t^n (\sum_{k|n} a_k/(n/k)) = \sum_{n=1}^inf t^n/n \sum_{k|n}ka_k
-- d/dt:
-- S'(t)/S(t) = \sum_{n=1}^inf t^(n-1) \sum_{k|n}ka_k
-- S'(t) = S(t) * \sum ...
-- S(t) = \sum_{i=1}^inf s_i t^i
-- subsititute: \sum_{i=1} s_i i t^(i-1) = (\sum_{i=1} s_i t^i) (\sum_{n=1} t^(n-1) b_n)
--                                          b_n = \sum_{k|n}ka_k
-- i s_i = \sum_{m=1}^i s_{i-m} b_m
-- s_i = \sum_{m=1}^i s_{i-m} b_m / i, where b_m = \sum_{k|m}ka_k
solve n (S x) = res 
  where ans = solve n x
        divisors m = [d | d <- [1..m], m `mod` d == 0]
        b m = sum [k * ans !! k | k <- divisors m]
        res = 1:[ sum [res !! (i - m) * b m | m <- [1..i]] `div` i
                | i <- [1..n]]


-- L(X(t)):
-- L(X) = 1 + X(t) + X(t)^2 + ... (of length 0, of len 1, of len 2 ...), multiply possible chosen x from X
-- so gen fun: L_x(t) = 1 / (1 - X(t))
solve n (L x) = res
  where ans = solve n x
        res = 1:[sum [ans !! j * res !! (i - j) | j <- [1..i]] | i <- [1..n]] 
        -- res[0] = 1 <empty list>
        -- weight = 0 - banned; (ways of cur_weight - i) * (inner ways of weight i) -> ways of cur_weight


-- gen fun: P_x_y(t) = X(t)Y(t)
solve n (P x y) = [sum [ansX !! j * ansY !! (i - j) | j <- [0..i]] | i <- [0..n]] 
                -- ways[j]*ways[i-j] -> ways[i], i == j + (i - j)
  where (ansX, ansY) = (solve n x, solve n y)

printArr :: Show a => [a] -> IO ()
printArr a = putStrLn $ unwords $ map show a

main = getLine >>= return . parse >>= \(Just o) -> 
                                        printArr $ solve 6 o
