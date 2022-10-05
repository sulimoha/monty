#include "monty.h"

/**
 * parseLine - tokenise the line into tokens to extract the function to call
 * @buffer: line to be tokenised read from the file
 * @lineNumber: line Number
 *
 * Return: void
 */
void parseLine(char *buffer, int lineNumber)
{
	size_t i;
	char *opcode;
	char *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		errorI(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode != NULL)
	{
		for (i = 0; i < strlen(opcode); i++)
		{
			if(opcode[i] < 97 || opcode[i] > 122)
			{
				opcode[i] = '\0';
				break;
			}
		}
	}
	value = strtok(NULL, delim);
	if (value != NULL)
	{
		for (i = 0; i < strlen(value); i++)
		{
			if (isdigit(value[0]) != 0)
			{
				if(value[i] < 45 || value[i] > 57)
				{
					value[i] = '\0';
					break;
				}
			}
		}
	}
	if (strlen(opcode) == 0)
	{
		opcode = NULL;
	}
	pickFunc(opcode, value, lineNumber);
}
