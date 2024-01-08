import Control.Monad
import Data.List (sort)
import Data.Tuple
import qualified Data.Set as Set

(~>) = flip (.)
parseInt :: String -> Int
parseInt s = read s

ints :: String -> [Int]
ints = map parseInt . words

input = readFile "check.in"
output = writeFile "check.out"
-- input = getContents
-- output = putStrLn

pair [a, b] = (a, b)

diff [] _ = []
diff (a:as) b
  | elem a b = as
  | True     = a:diff as b

subsets [] = [[]]
subsets (x:xs) = let r = subsets xs in r ++ map (x:) r

insert x [] = [x]
insert x (a:as) = if x <= a then x:a:as else a:insert x as

remove v xs = [x | x <- xs, x /= v]

solve (n, m, sets) = 
  let raw'sets = map snd sets
      sr = Set.fromList raw'sets
      ax1 = elem [] raw'sets
      ax2 = all (\a -> all (\s -> elem (remove s a) raw'sets) a) raw'sets
      ax3 = all (\(a, b) -> 
                  any (\x -> Set.member (insert x b) sr) $ diff a b)
                [(a, b) | (n'a, a) <- sets, (n'b, b) <- sets, n'a > n'b]
  in ax1 && ax2 && ax3

parse ls = 
  let split (n:a) = (n, sort a)
      [n, m] = ints $ head ls
      sets = map (split.ints) $ tail ls
      in (n, m, sets)

en True = "YES"
en False = "NO"
main = input >>= lines ~> parse ~> solve ~> en ~> output
