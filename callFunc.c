#include "monty.h"

/**
 * callFunc - calls the proper function
 * @func: apointer to the function to be called
 * @opcode: opcode
 * @value: the value of the opcode
 * @lineNumber: lineNumber
 *
 * Return: void
 */
void callFunc(opcodeFunc func, char *opcode, char *value, int lineNumber)
{
	stack_t *node;
	int i;
	int flag = 1;

	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value++;
			flag = -1;
		}
		if (value != NULL && value[0] == '+')
		{
			value++;
			flag = 1;
		}
		if (value == NULL)
		{
			errorI(5, lineNumber);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				errorI(5, lineNumber);
			}
		}
		node = createNode(flag * atoi(value));
		func(&node, lineNumber);
	}
	else
	{
		func(&head, lineNumber);
	}
}