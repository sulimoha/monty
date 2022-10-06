#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void pchar(stack_t **stackHead, unsigned int lineNumber)
{
	int ascii;

	if (stackHead == NULL || *stackHead == NULL)
	{
		errorIII(15, lineNumber);
	}
	ascii = (*stackHead)->n;
	if (ascii < 0 || ascii > 127)
	{
		errorIII(16, lineNumber);
	}
	printf("%c\n", ascii);
}
