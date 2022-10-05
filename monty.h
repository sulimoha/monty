#ifndef HEADER_H
#define HEADER_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>



/**

 * struct stack_s - doubly linked list representation of a stack (or queue)

 * @n: integer

 * @prev: points to the previous element of the stack (or queue)

 * @next: points to the next element of the stack (or queue)

 *

 * Description: doubly linked list node structure

 * for stack, queues, LIFO, FIFO

 */

typedef struct stack_s

{

        int n;

        struct stack_s *prev;

        struct stack_s *next;

} stack_t;

/**

 * struct instruction_s - opcode and its function

 * @opcode: the opcode

 * @f: function to handle the opcode

 *

 * Description: opcode and its function

 * for stack, queues, LIFO, FIFO

 */

typedef struct instruction_s

{

        char *opcode;

        void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;


/*declaring head as a global variable*/
extern stack_t *head;

/* redfining parameter type*/
typedef void (*opcodeFunc)(stack_t **, unsigned int);

/*file handling */
void openFile(char *fileName);
void readFile(FILE *fd);

/*parser*/
void parseLine(char *buffer, int lineNumber) ;

/*function handling*/
void pickFunc(char *opcode, char *value, int lineNumber);
void callFunc(opcodeFunc func, char *opcode, char *value, int lineNumber);

/*node handling*/
stack_t *createNode(int n);
void freeNode(void);

/*error handling*/
void errorI(int errorType, ...);

/*stack functions handling*/
void pushElement(stack_t  **newElement, unsigned int);
void printStack(stack_t **stackHead, unsigned int);
void printTopElement(stack_t ** stackHead, unsigned int lineNumber);
#endif