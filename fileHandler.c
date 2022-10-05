#include "monty.h"

/**
 * openFile - opens a file
 * @fileName: the file namepath
 *
 * Return: void
 */
void openFile(char *fileName)
{
/**Opens a file for reading. The file must exist.*/
	FILE *fd = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)
	{
		error(2, fileName);
	}
	readFile(fd);
	fclose(fd);
}

/**
 * readFile - reads a file
 * @fd: a pointer to the file descriptor
 *
 * Return: void
 */
void readFile(FILE *fd)
{
	int lineNumber;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNumber = 1; getline(&buffer, &len, fd) != -1; lineNumber++)
	{
		parseLine(buffer, lineNumber);
	}
	free(buffer);
}
