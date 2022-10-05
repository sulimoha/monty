#include "monty.h"

/**
 * errorI - prints the error messsage according to the error type
 * @errorType: number represents the error type
 *
 * Return: void
 */
void errorI(int errorType, ...)
{
	va_list args;
	char *opcode;
	int lineNumber;

	va_start(args, errorType);
	switch (errorType)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			lineNumber = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n",  va_arg(args, int));
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}
