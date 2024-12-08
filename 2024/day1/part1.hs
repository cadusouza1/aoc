module Main where

import           Data.List (sort)


main :: IO ()
main = do
    inputData <- lines <$> readFile "input.txt"
    let ids = [(read x, read y) | line <- inputData, let [x, y] = words line]
    let (leftIds, rightIds) = unzip ids
    let answer = sum $ zipWith (-) (sort leftIds) (sort rightIds)

    print answer
