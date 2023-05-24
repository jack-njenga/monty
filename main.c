#include "monty.h"
/**
 * main - Entry point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 on success otherwise on error
 */

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 2)
	{
		_default();
	}
	else
	{
		filename = argv[1];
		/*printf("%s NICE\n", argv[1]);*/
		check_file();
		populate();
		first = NULL;
		check_command();
	}

	return (0);
}
