#include "monty.h"
/**
 * pickFunc - picks the proper function to handel the opcode
 * @opcode: opcode
 * @value: argument of the opcode
 * @lineNumber: lineNumber
 * @dataFormat: stack (default) or queue
 */
void pickFunc(char *opcode, char *value, int lineNumber, int dataFormat)
{
	int i, flag;
	instruction_t funcList[] = {
		{"push", pushElement},
		{"pall", printStack},
		{"pint", printTopElement},
		{"pop", popElement},
		{"swap", swapTopTwoElements},
		{"add", addTopTwoElements},
		{"nop", nop},
		{"sub", subTopTwoElements},
		{"div", divTopTwoElements},
		{"mul", mulTopTwoElements},
		{"mod", modTopTwoElements},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode == NULL && value == NULL)
	{
		return;
	}
	if (opcode[0] == '#')
	{
		return;
	}
	for (flag = 1, i = 0; funcList[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funcList[i].opcode) == 0)
		{
			callFunc(funcList[i].f, opcode, value, lineNumber, dataFormat);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		errorI(3, lineNumber, opcode);
	}
}
