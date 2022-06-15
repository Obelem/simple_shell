#include "shell.h"

/**
 * file_path - adds path and checks if command exists
 * @argv: pointer to argv
 * @argc: pointer to argc
 * @cmd: command input
 * @line_size: command length
 * Return: process status
 */


int file_path(char **argv, int argc, char *cmd, ssize_t line_size)
{
	int len = 0;
	char *buf = NULL;
	struct stat cmd_stat;

	while (argv[0][len])
		len++;
	if (strcmp(argv[0], "exit") == 0)
		return (exit_process(argc, argv));
	if (strcmp(argv[0], "setenv") == 0)
		return (_setenv(argc, argv));
	if (strcmp(argv[0], "cd") == 0)
		return (change_dir(argc, argv));
	if (strcmp(argv[0], "pwd") == 0)
		print_pwd();
	if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argc != 2)
		{
			write(2, ":( syntax -> unsetenv VARIABLE\n", 31);
			return (-1);
		}
		return (_unsetenv(argv));
	}
	if (argv[0][0] != '/')
	{
		buf = malloc(sizeof(char) * len);
		_strncpy(buf, argv[0], len);
		argv[0] = malloc(sizeof(char) * (len + 5));
		_strcpy(argv[0], "/bin/");
		_strcat(argv[0], buf);
		free(buf);
	}
	if (stat(argv[0], &cmd_stat) == 0)
		read_cmd(argv, cmd, line_size);
	else
	{
		write(2, ":( Command does not exist\n", 26);
		free(argv), free(cmd), prompt();
	}
	return (0);
}
