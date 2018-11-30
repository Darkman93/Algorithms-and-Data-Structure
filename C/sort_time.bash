#!/bin/bash
for i in `seq 1 3`;
do
  filename="./times/sort_times$i.md"
  ./dictionary.out > $filename
done