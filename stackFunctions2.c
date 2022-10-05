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

/**
 * popElement - pops the top element of the  stack
 * @stackHead: the head of the stack
 * @lineNumber: the line number of the opcode
 *
 * Return: void
 */
void popElement(stack_t **stackHead, unsigned int lineNumber)
{
	stack_t *temp;

	if (stackHead == NULL || *stackHead == NULL)
	{
		errorI(7, lineNumber);
	}
	temp = *stackHead;
	*stackHead = temp->next;
	if (*stackHead != NULL)
	{
		(*stackHead)->prev = NULL;
	}
	free(temp);
}

