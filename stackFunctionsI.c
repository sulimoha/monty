#include "monty.h"

/**
 * pushElement - pushes an element to the stack
 * @newElement: a pointer to the new element to be pushed
 * @lineNumber: line number of opcode
 *
 * Return: void
 */
void pushElement(stack_t  **newElement, unsigned int lineNumber)
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
	head = *newElement;
	head->next = temp;
	temp->prev = head;
}

/**
 * printStack - prints the stack elements
 * @stackHead: a pointer to the stack head
 * @lineNumber: line number of opcode
 *
 * Return: void
 */
void printStack(stack_t **stackHead, unsigned int lineNumber)
{
	stack_t *temp;

	(void) lineNumber;
	if (stackHead == NULL)
	{
		exit(EXIT_FAILURE);
	}
	temp = *stackHead;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


