#include "shell.h"

/**
 * read_cmd - Function to read and execute inputs
 * @argv: Pointer to argumnets pointers
 * @cmd: command line input
 * @line_size: length of cmd
 *
 */

void read_cmd(char **argv, char *cmd, ssize_t line_size)
{
	int i, j;
	char *ptr;
	char special_char[7] = {34, 39, 96, 92, 42, 38, 35};

	if (!cmd)
		exit(EXIT_FAILURE);

	ptr = malloc(sizeof(char) * line_size);

	if (!ptr)
		exit(EXIT_FAILURE);


	for (i = 0; i < line_size; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (cmd[i] == special_char[j])
			{
				write(2, "./shell: No such file or directory\n", 35);
				free(cmd);
				prompt();
				return;
			}
		}
		ptr[i] = cmd[i];
	}
	ptr[i] = '\0';

	if (fork() != 0)
	{
		wait(NULL);
		free(cmd);
		prompt();
	}
	else
	{
		if (execve(argv[0], argv, NULL) == -1)
			write(2, "./Xshell: No such file or directory\n", 36);
	}
}
