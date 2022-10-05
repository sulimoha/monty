#include "monty.h"

/**
 * pickFunc - picks the proper function to handel the opcode
 * @opcode: opcode
 * @value: argument of the opcode
 * @lineNumber: lineNumber
 *
 * Return: void
 */
void pickFunc(char *opcode, char *value, int lineNumber)
{
	int i;
	int flag;
	instruction_t funcList[] = {
		{"push", pushElement},
		{"pall", printStack},
		{NULL, NULL}
	};

	for (flag = 1, i = 0; funcList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcList[i].opcode) == 0)
		{
			callFunc(funcList[i].f, opcode, value, lineNumber);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		error(3, lineNumber, opcode);
	}
}

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
		if (value == NULL)
		{
			error(5, lineNumber);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				error(5, lineNumber);
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
