-- A function that checks if a report is safe without any removal.
isSafe :: [Int] -> Bool
isSafe report =
    let diffs = zipWith (-) (tail report) report
    in isMonotonic diffs && all (\d -> abs d <= 3 && d /= 0) diffs
  where
    isMonotonic (d:ds) = all (\x -> (x >= 0) == (d>=0)) ds  -- all diffs same sign, handle carefully

-- A function that checks if a report can be made safe by removing one level.
isSafeWithRemoval :: [Int] -> Bool
isSafeWithRemoval report
    | isSafe report = True
    | otherwise = any (isSafe . removeIndex report) [0..length report - 1]
  where
    removeIndex xs i = let (before, after) = splitAt i xs in before ++ tail after

main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let reports = map (map read . words) inputData :: [[Int]]
    print $ length (filter isSafeWithRemoval reports)
