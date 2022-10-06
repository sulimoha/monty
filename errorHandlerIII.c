#include "monty.h"

/**
 * errorIII - prints the error messsage according to the error type
 * @errorType: number represents the error type
 */
void errorIII(int errorType, ...)
{
	va_list args;
	char *opcode;
	int lineNumber;

	va_start(args, errorType);
	(void)opcode;
	switch (errorType)
	{
		case 14:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
			break;
		case 15:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
			break;
		case 16:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}
