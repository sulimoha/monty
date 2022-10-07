#include "monty.h"
/**
 * enqueueElement - enqueue an element to the queue
 * @newElement: a pointer to the new element to be enqueued
 * @lineNumber: line number of opcode
 */
void enqueueElement(stack_t **newElement, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (newElement == NULL || *newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *newElement;
		return;
	}
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *newElement;
	(*newElement)->prev = temp;
}
