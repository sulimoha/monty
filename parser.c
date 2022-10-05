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
	char *opcode;
	char *value;
	const char *delim = "\n $";

	if (buffer == NULL)
	{
		errorI(4);
	}
	opcode = strtok(buffer, delim);
	value = strtok(NULL, delim);
	pickFunc(opcode, value, lineNumber);
}
