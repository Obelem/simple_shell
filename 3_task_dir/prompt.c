#include "shell.h"

/**
 * prompt - get and read input
 *
 */

void prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t line_size = 0;

	while (line_size != EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);

		line_size = getline(&line, &len, stdin);

		if (line_size == -1)
			break;

		if (line_size != 1)
			tokenifier(line, line_size - 1);
	}

	free(line);

	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);

}
