#include "monty.h"
/**
 * check_file - checks if the file is legit
 */

void check_file(void)
{
	struct stat path_info;
	const char *file;

	file = global.filename;
	if (access(file, F_OK) != -1)
	{
		if (stat(file, &path_info) == 0)
		{
			if (S_ISREG(path_info.st_mode))
				read_file();
		}
		else
			error_file();
	}
	else
		error_file();
}

/**
 * read_file - reads the file
 */
void read_file(void)
{
	int nread, i, line = 0;
	size_t len = 0;
	const char *file;
	char *cmd = NULL, *token;
	FILE *fd;

	file = global.filename;
	fd = fopen(file, "r");
	if (fd == NULL)
		error_file();

	while (nread = getline(&cmd, &len, fd) != -1)
	{
		line++;
		token = strtok(cmd, "\t\n");
		if (!token)
			continue;
		printf("L%d: %s\n", line, token);
		populate(token, line);
	}
	if (nread == -1)
		error_read();
	fclose(fd);
	/*printf("%s\n", global.content);*/
}
/**
 * populate - populate the commands
 */
void populate(char *token, int line)
{
	char *cmd[MIN_ARR], *str;
	int i = 0;

	str = strtok(token, " ");
	while (str != NULL)
	{
		cmd[i] = str;
		str = strtok(NULL, " ");	
	}
	cmd[i] = '\0';
	if (cmd[0] != NULL)
	{
		command_checker(cmd, line);
	}
}
