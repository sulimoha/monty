#include "monty.h"
/**
 * mulTopTwoElements - multiplies the second top element of
 * the stack with the top element of the stack
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void mulTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	int sum;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorII(13, lineNumber);
	}
	(*stackHead) = (*stackHead)->next;
	sum = (*stackHead)->n * (*stackHead)->prev->n;
	(*stackHead)->n = sum;
	free((*stackHead)->prev);
	(*stackHead)->prev = NULL;
}
/**
 * modTopTwoElements - computes the rest of the division of
 * the second top element of the stack by the
 * top element of the stack.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void modTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	int sum;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorIII(14, lineNumber);
	}
	if ((*stackHead)->n == 0)
	{
		errorII(12, lineNumber);
	}
	(*stackHead) = (*stackHead)->next;
	sum = (*stackHead)->n % (*stackHead)->prev->n;
	(*stackHead)->n = sum;
	free((*stackHead)->prev);
	(*stackHead)->prev = NULL;
}
