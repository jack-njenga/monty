#include "monty.h"
/**
 */
void check_command()
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
				//printf("[%d] :: %s \n", n, _command[n]);
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
 */

void command_helper(char **cmd, int line)
{
	int num;

	line = line + 1;
	if (*cmd != NULL)
	{
		if (strcmp(cmd[0], "push") == 0)
		{
			if (cmd[1] != NULL)
			{
				if (cmd[1][0] == '0')
				{
					//printf("push time\n");
					push(0);
				}
				else
				{
					num = atoi(cmd[1]);
					if (num == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
					//printf("push time 2\n");
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
		{
			//printf("pall time\n");
			pall();
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, commands[line - 1]);
			exit(EXIT_FAILURE);
		}	
	}
}
