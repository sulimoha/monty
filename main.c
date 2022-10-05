#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		errorI(1);
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNode();
	return (0);
}
