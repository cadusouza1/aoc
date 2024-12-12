module Main where

pairs xs = zip xs $ tail xs

main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let levels = map (map read . words) inputData :: [[Int]]
    let levelPairs = map pairs levels
    let runningDifs = map (map (uncurry (-))) levelPairs
    let safeByDiff = filter (all ((\x -> x <= 3 && x /= 0) . abs)) runningDifs
    let safeByIncOrDec = filter (all (\(x, y) -> x * y > 0)) (map pairs safeByDiff)

    print $ length safeByIncOrDec
