#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void nop(stack_t **stackHead, unsigned int lineNumber)
{
	(void) stackHead;
	(void) lineNumber;
}
/**
 * subTopTwoElements - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void subTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	int sum;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorII(10, lineNumber);
	}
	(*stackHead) = (*stackHead)->next;
	sum = (*stackHead)->n - (*stackHead)->prev->n;
	(*stackHead)->n = sum;
	free((*stackHead)->prev);
	(*stackHead)->prev = NULL;
}
/**
 * divTopTwoElements - divides the second top element of the stack
 * by the top element of the stack.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void divTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	int sum;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorII(11, lineNumber);
	}
	if ((*stackHead)->n == 0)
	{
		errorII(12, lineNumber);
	}
	(*stackHead) = (*stackHead)->next;
	sum = (*stackHead)->n / (*stackHead)->prev->n;
	(*stackHead)->n = sum;
	free((*stackHead)->prev);
	(*stackHead)->prev = NULL;
}
