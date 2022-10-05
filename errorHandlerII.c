#include "monty.h"

/**
 * errorII - prints the error messsage according to the error type
 * @errorType: number represents the error type
 */
void errorII(int errorType, ...)
{
	va_list args;
	char *opcode;
	int lineNumber;

	va_start(args, errorType);
	switch (errorType)
	{
		(void)opcode;
		case 8:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
			break;
		case 9:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
			break;
		case 10:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
			break;
		case 11:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
			break;
		case 12:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: division by zero\n", lineNumber);
			break;
		case 13:
			lineNumber = va_arg(args, int);
			fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
			break;
		default:
			break;
	}
	freeNode();
	exit(EXIT_FAILURE);
}
