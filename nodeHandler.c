#include "monty.h"

/**
 * createNode - creates a node
 * @n: data of the node
 *
 * Return: a pointer to the node if success or NULL if failed
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		error(4);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * freeNode - free the memory allocated to the node
 *
 * Return: void
 */
void freeNode(void)
{
	stack_t *temp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
