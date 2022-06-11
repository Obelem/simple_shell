#include "shell.h"

/**
 * exit_process - exits process with status
 * @argv: tokenized input string array
 * Return: 1 on failure, 0 on success
 */

int exit_process(char **argv)
{
	int ret_val = 0, i;
	
	if (!argv[1])
		exit(0);
	
	if (argv[1])
	{
		if (argv[2])
		{
			write(2, ":( too many arguments\n", 22);
			prompt();
			return (1);
		}
		for (i = 0; argv[1][i]; i++)
		{
			if (isdigit(argv[1][i]) == 0)
			{
				write(2, ":( input integers only\n", 23);
				prompt();
				return (1);
			}
		}
		ret_val = atoi(argv[1]);
		exit(ret_val);
	}
	return (0);
}
