#!/bin/bash
echo =========== betty tests ========
betty *.c
echo =================== Compilation \& Output ======
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
echo ========  ./monty bytecodes/000.m ========
./monty bytecodes/000.m
echo ================ ./monty bytecodes/001.m =========
./monty bytecodes/001.m
echo ============== 0. push, pall =========
./monty bytecodes/00.m
echo ==================== 1. pint ==========
./monty bytecodes/06.m  
echo ==================== 2. pop ========
./monty bytecodes/07.m
echo ============== 3. swap ==========
./monty bytecodes/09.m
echo ============ 4. add ============
./monty bytecodes/12.m
