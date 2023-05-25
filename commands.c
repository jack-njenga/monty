#include "monty.h"
void command_helper(char **cmd, int line);
/**
 * command_checker - checks the commands
 * @cmd: commands
 * @line: line of the commands
 */
void command_checker(char **cmd, int line)
{
	int num;

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
			pint(line);
		else if (strcmp(cmd[0], "pop") == 0)
			pop(line);
		else if (strcmp(cmd[0], "swap") == 0)
			swap(line);
		else if (strcmp(cmd[0], "add") == 0)
			add(line);
		else if (strcmp(cmd[0], "nop") == 0)
			(void)line;
		else
			command_helper(cmd, line);
	}
}
/**
 * command_helper - command helper
 * @cmd: ccommand
 * @line: line of the command
 */
void command_helper(char **cmd, int line)
{
	if (strcmp(cmd[0], "sub") == 0)
		sub(line);
	else if (strcmp(cmd[0], "div") == 0)
		_div(line);
	else if (strcmp(cmd[0], "mul") == 0)
		mul(line);
	else if (strcmp(cmd[0], "mod") == 0)
		mod(line);
	else
		error_command(line, cmd[0]);
}
