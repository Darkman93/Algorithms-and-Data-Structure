#!/bin/bash
for i in `seq 1 6`;
do
  filename="./times/dictionary_times$i.md"
  ./dictionary.out > $filename
done