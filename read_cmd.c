#include "shell.h"

void read_cmd(char *cmd, ssize_t line_size)
{
	int i;
	char *ptr;
	char *argv[] = {ptr, NULL};

	if (!cmd)
		exit(EXIT_FAILURE);

	ptr = malloc(sizeof(char) * line_size);

	if (!ptr)
		exit(EXIT_FAILURE);

	/* checks if command has only lowercase characters */
	for (i = 0; i < line_size; i++)
	{

		if ((cmd[i] >= 'a' && cmd[i] <= 'z') || cmd[i] == '/')
			ptr[i] = cmd[i];	
		else
		{
			write(2, "./shell: No such file or directory\n", 35);
			free(cmd);
			prompt();
		}
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
