#include "monty.h"

/**
 * swapTopTwoElements - swaps the top two elements of the stack.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void swapTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	stack_t *temp;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorI(8, lineNumber);
	}
	temp = (*stackHead)->next;
	(*stackHead)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *stackHead;
	}
	temp->next = *stackHead;
	(*stackHead)->prev = temp;
	temp->prev = NULL;
	*stackHead = temp;
}
/**
 * addTopTwoElements - adds the top two elements of the stack.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void addTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
	int sum;

	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		errorI(9, lineNumber);
	}
	(*stackHead) = (*stackHead)->next;
	sum = (*stackHead)->n + (*stackHead)->prev->n;
	(*stackHead)->n = sum;
	free((*stackHead)->prev);
	(*stackHead)->prev = NULL;
}
