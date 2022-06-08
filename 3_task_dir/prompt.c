#include "shell.h"

/**
 * prompt - get and read input 
 */

/* Built in global variable to help access environment variables */
extern char **environ;

void prompt(void)
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

		line_size = getline(&line, &len, stdin);

		/* compares if input is env and prints env variables if true */
		compare = strncmp(env, line, 3);
		if (compare == 0)
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			
			prompt();
		}

		if (line_size == -1)
			break;

		if (line_size != 1)
			tokenifier(line, line_size - 1);
	}


	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

}
