#include "monty.h"
/**
 * check_command - checks the commands and tokenizes it
 *
 * Return: void
 */
void check_command(void)
{
	int i = 0, n = 0;
	char *_command[MIN_ARR];
	char *dell = " ";

	if (*commands != NULL)
	{

		while (commands[i] != NULL)
		{
			n = 0;
			_command[n] = strtok(commands[i], dell);
			while (_command[n] != NULL)
			{
				/*printf("[%d] :: %s \n", n, _command[n]);*/
				n++;
				_command[n] = strtok(NULL, dell);
			}
			_command[n] = '\0';
			command_helper(_command, i);
			i++;
		}
	}
}

/**
 * command_helper - checks for the command
 * @cmd: the address of the command
 * @line: line of the command
 *
 * Return: void
 */

void command_helper(char **cmd, int line)
{
	int num;
	char *str;

	line = line + 1;
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
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
					push(num);
				}
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(cmd[0], "pall") == 0)
			pall();
		else if (strcmp(cmd[0], "pint") == 0)
			pint();
		else
		{
			str = commands[line - 1];
			fprintf(stderr, "L%d: unknown instruction %s\n", line, str);
			exit(EXIT_FAILURE);
		}
	}
}
