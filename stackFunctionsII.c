#include "monty.h"

/**
 * printTopElement - prints the top element of the stack
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void printTopElement(stack_t **stackHead, unsigned int lineNumber)
{
	if (stackHead == NULL || *stackHead == NULL)
	{
		errorI(6, lineNumber);
	}
	printf("%d\n", (*stackHead)->n);
}
