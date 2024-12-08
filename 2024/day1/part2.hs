module Main where

import qualified Data.Map   as M
import qualified Data.Maybe


main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let rawNumbers = map words inputData
    let ids = map (map read) rawNumbers :: [[Int]]
    let leftIds = map (!! 0) ids
    let rightIds = map (!! 1) ids

    let rightCounter = M.fromListWith (+) [(x, 1) | x <- rightIds]
    let answer = sum $ map (\n -> n * (Data.Maybe.fromMaybe 0 . (`M.lookup` rightCounter)) n) leftIds

    print answer
