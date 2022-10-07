#include "monty.h"
/**
 * callFunc - calls the proper function
 * @func: apointer to the function to be called
 * @opcode: opcode
 * @value: the value of the opcode
 * @lineNumber: lineNumber
 * @dataFormat: stack or queue
 */
void callFunc(opcodeFunc func, char *opcode, char *value,
	int lineNumber, int dataFormat)
{
	stack_t *node;
	int i;
	int flag = 1;

	(void) dataFormat;
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
			errorI(5, lineNumber);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				errorI(5, lineNumber);
		}
		node = createNode(flag * atoi(value));
		if (dataFormat == 0)
			func(&node, lineNumber);
		if (dataFormat == 1)
			enqueueElement(&node, lineNumber);
	}
	else
		func(&head, lineNumber);
}
