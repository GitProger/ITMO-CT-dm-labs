import Control.Monad
import Data.List (sort, sortOn)
import Data.Tuple
import qualified Data.Set as Set

(~>) = flip (.)
parseInt :: String -> Int
parseInt s = read s

ints :: String -> [Int]
ints = map parseInt . words

input = readFile "cycles.in"
output = writeFile "cycles.out"
-- input = getContents
-- output = putStrLn

intersec [] _ = []
intersec (a:as) b
  | elem a b = a:intersec as b
  | True     = intersec as b

insert x [] = [x]
insert x (a:as)
  | x <= a = x:a:as 
  | x == a = a:as
  | True   = a:insert x as

indexed a = zip a [1..]

solve :: (Int, Int, [(Int, Int)], [(Int, [Int])]) -> Int
solve (n, m, w, sets') =
  let sets = map snd sets'
      iter (ans, mx) mem =
        let bad = any (\cycl ->
                    let un = intersec cycl $ insert (snd mem) mx
                    in un == cycl
                  ) sets
        in
          if bad 
            then (ans, mx) 
            else (ans + fst mem, insert (snd mem) mx)
  in
    fst $ foldl iter (0, []) w

parse :: [String] -> (Int, Int, [(Int, Int)], [(Int, [Int])])
parse ls = 
  let split (n:a) = (n, sort a)
      [n, m] = ints $ head ls
      w = ints $ head $ tail ls
      w' = reverse $ sortOn fst $ indexed w
      sets = map (split.ints) $ tail $ tail ls
      in (n, m, w', sets)


main = input >>= lines ~> parse ~> solve ~> show ~> output
