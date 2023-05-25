#include "monty.h"
/**
 * _default - prints the errors
 */
void _default(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_file - prints the errors
 */
void error_file(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", global.filename);
	exit(EXIT_FAILURE);
}
/**
 * error_read - reading errors
 */
void error_read(void)
{
	fprintf(stderr, "Error: Can't read file %s\n", global.filename);
	exit(EXIT_FAILURE);
}
/**
 * error_push - error when pushing
 * @line: line number
 */
void error_push(int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * error_command - wrong command error
 * @line: line of error
 * @str: wrong command
 */
void error_command(int line, char *str)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
	exit(EXIT_FAILURE);
}
