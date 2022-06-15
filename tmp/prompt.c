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

	write(1, "#cisfun$ ", 9);

	line_size = getline(&line, &len, stdin);

	tokenifier(line, line_size - 1);
}
