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
echo ================ 6. sub =============
./monty bytecodes/19.m
echo ================ 7. div =================
./monty bytecodes/19div.m
echo ================ 8. mul =================
./monty bytecodes/19mul.m
echo ================ 9. mod =================
./monty bytecodes/19mod.m
echo ================ 10. comments =================
./monty bytecodes/19comm.m
echo ================ 11. pchar =================
./monty bytecodes/28.m
echo ================ 12. pstr =================
./monty bytecodes/31.m 
echo ================ 13. rotl =================
./monty bytecodes/35.m 
echo ================ 14. rotr =================
./monty bytecodes/355.m 
