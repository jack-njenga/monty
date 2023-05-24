#include "monty.h"
/**
 */
void read_file()
{
	int f_d, nbytes;

	f_d = open(filename, O_RDONLY);

	/*printf("f_d : %d\n", f_d);*/
	if (f_d == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	nbytes = read(f_d, content, BUFFER_SIZE);
	close(f_d);
	/*printf("%d characters\n%s", nbytes, content);*/
}

/**
 */

void populate()
{
	int i = 0;
	char *dell = "\n";

	if (content != NULL)
	{
		commands[i] = strtok(content, dell);
		while (commands[i] != NULL)
		{
			printf("[%d] : %s\n", i, commands[i]);
			i++;
			commands[i] = strtok(NULL, dell);
		}
		commands[i] = '\0';
	}
}
