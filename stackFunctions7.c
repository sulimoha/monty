#include "monty.h"
/**
 * rotl -  rotates the stack to the top
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void rotl(stack_t **stackHead, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		return;
	}
	temp = *stackHead;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stackHead;
	(*stackHead)->prev = temp;
	*stackHead = (*stackHead)->next;
	(*stackHead)->prev->next = NULL;
	(*stackHead)->prev = NULL;
}
/**
 * rotr - rotates the stack to the bottom.
 * @stackHead: a pointer to the head of the stack
 * @lineNumber: the line number of the opcode
 */
void rotr(stack_t **stackHead, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stackHead == NULL || *stackHead == NULL || (*stackHead)->next == NULL)
	{
		return;
	}
	temp = *stackHead;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stackHead;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stackHead)->prev = temp;
	*stackHead = temp;
}
