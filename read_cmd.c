#include "shell.h"

void read_cmd(char *cmd, ssize_t line_size)
{
	int i, j;
	char *ptr;
	char *argv[] = {NULL, NULL};
	char special_char[8] = {34, 39, 96, 92, 42, 38, 35, 32};

	if (!cmd)
		exit(EXIT_FAILURE);

	ptr = malloc(sizeof(char) * line_size);
	if (!ptr)
		exit(EXIT_FAILURE);
	argv[0] = ptr;
	for (i = 0; i < line_size; i++)
	{
		for (j = 0; j < 8; j++)
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
		if (execve(ptr, argv, NULL) == -1)
			write(2, "./shell: No such file or directory\n", 35);
	}
}
