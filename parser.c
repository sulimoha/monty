#include "monty.h"
/**
 * parseLine - tokenise the line into tokens to extract the function to call
 * @buffer: line to be tokenised read from the file
 * @lineNumber: line Number
 * @dataFormat: format of the data default is stack(LIFO) or queue (FIFO)
 *
 * Return: 0 if stack, 1 if queue
 */
int parseLine(char *buffer, int lineNumber, int dataFormat)
{
	size_t i;
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errorI(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (dataFormat);
	if (opcode != NULL)
	{
		for (i = 0; i < strlen(opcode); i++)
		{
			if (opcode[i] < 97 || opcode[i] > 122)
				return (dataFormat);
		}
	}
	value = strtok(NULL, delim);
	if (value != NULL)
	{
		for (i = 0; i < strlen(value); i++)
		{
			if (isdigit(value[0]) != 0)
			{
				if (value[i] != 43  && value[i] != 45 && (value[i] < 48 || value[i] > 57))
				{
					value[i] = '\0';
					break;
				}
			}
		}
	}
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	pickFunc(opcode, value, lineNumber, dataFormat);
	return (dataFormat);
}
