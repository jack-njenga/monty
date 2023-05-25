#include "monty.h"
/**
 * main - Entry point
 * @argc: argument counter
 * @argv: argument vectoe
 *
 * Return: 0 on success otherwise error
 */
int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 2)
	{
		_default();
	}
	else
	{
		global.filename = argv[1];
		check_file();
	}
	return (0);
}
