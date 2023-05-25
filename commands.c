#include "monty.h"
/**
 * command_checker - checks the commands
 * @cmd: commands
 * @line: line of the commands
 */
void command_checker(char **cmd, int line)
{
	int num;
	char *str, **commands;

	if (*cmd != NULL)
	{
		if (strcmp(cmd[0], "push") == 0)
		{
			if (cmd[1] != NULL)
			{
				if (cmd[1][0] == '0')
					push(0);
				else
				{
					num = atoi(cmd[1]);
					if (num == 0)
						error_push(line);
					push(num);
				}
			}
			else
				error_push(line);
		}
		else if (strcmp(cmd[0], "pall") == 0)
			pall();
		else if (strcmp(cmd[0], "pint") == 0)
			pint();
		else
			error_command(line, cmd[0]);
	}
}
