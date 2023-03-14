#!/bin/bash
./generate 1000000 100000 999999
time sort numbers.txt > sysSort.out
time ./mySort numbers.txt mySort.out
time ./mySortA numbers.txt mySortA.out
time ./mySortB numbers.txt mySortB.out