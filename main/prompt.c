#include "shell.h"

/**
 * prompt - get and read input 
 */

/**
 * 1. removed _exit string, this check is performed in tokenifer() and executed
 * in exit_process() (...see built-ins.c file)
 * 2. changed return type to int to handle exit status
 * returns 1 on success and 0 on failure
 */
int prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size = 0;
	int i, compare;
	char *env = "env";

	while (line_size != EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, ":) ", 3);

		line_size = _getline(&line, &len, stdin);

		/* compares if input is env and prints env variables if true */
		compare = _strncmp(env, line, 3);
		if (compare == 0)
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			
			prompt();
			return (1);
		}

		if (line_size == -1)
			break;

		if (line_size != 1)
			tokenifier(line, line_size - 1);
	}
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

	return (0);
}
