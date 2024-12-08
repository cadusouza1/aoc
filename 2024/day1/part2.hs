module Main where

import qualified Data.Map   as M
import qualified Data.Maybe


main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let ids = [(read l, read r) | line <- inputData, let [l, r] = words line]
    let (leftIds, rightIds) = unzip ids

    let rightFreqs = M.fromListWith (+) [(r, 1) | r <- rightIds]
    let score = sum [ l * M.findWithDefault 0 l rightFreqs | l <- leftIds ]

    print score
