#include "monty.h"
/**
 * check_file - checks if the file is legit
 *
 * Return: void
 */

void check_file()
{
	struct stat path_info;

	if (access(filename, F_OK) != -1)
	{
		/*printf("%s is a legit file\n", filename);*/
		if (stat(filename, &path_info) == 0)
		{
			if (S_ISREG(path_info.st_mode))
			{
				read_file();
			}
			else
				fprintf(stderr, "Error: Can't open file %s\n", filename);
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
