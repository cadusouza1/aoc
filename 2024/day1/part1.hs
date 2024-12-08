module Main where

import           Data.List (sort)


main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let rawNumbers = map words inputData
    let ids = map (map read) rawNumbers :: [[Int]]
    let leftIds = sort $ map (!! 0) ids
    let rightIds = sort $ map (!! 1) ids
    let answer = sum $ map (\(x, y) -> x - y) (zip leftIds rightIds)

    print answer
