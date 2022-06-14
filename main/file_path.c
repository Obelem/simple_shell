#include "shell.h"

/**
 * file_path - adds path and checks if command exists
 * @cmd: command input
 * @line_size: command length
 * Return: process status
 */

/**
 * == Changes ==
 * 1. return type changed from void to int to retrieve exit status
 * 2. added a call to exit_process() to handle the exit status conditions
 * 3. ends with return 0 for success
 */
int file_path(char **argv, int argc, char *cmd, ssize_t line_size)
{
	int len = 0;
	char *buf = NULL;
	struct stat cmd_stat;

	while (argv[0][len])
		len++;
	
	/* for built-in exit command */
	if (strcmp(argv[0], "exit") == 0)
		return (exit_process(argc, argv));


	/* for built in setenv and unsetenv command */
	if (strcmp(argv[0], "setenv") == 0)
		return (_setenv(argc, argv));

	/* for built in cd command */
	if (strcmp(argv[0], "cd") == 0)
		return (change_dir(argc, argv));

	if (strcmp(argv[0], "pwd") == 0)
		print_pwd();


	if (argv[0][0] != '/')
	{
		buf = malloc(sizeof(char) * len);
		
		/* copy text in argv[0] to buf */
		_strncpy(buf, argv[0], len);
		
		/* update value of argv[0] */
		argv[0] = malloc(sizeof(char) * (len + 5));
		_strcpy(argv[0], "/bin/");

		/* append text from buffer to argv[0] */
		_strcat(argv[0], buf);

		/* free buf when done */
		free(buf);
	}
	if (stat(argv[0], &cmd_stat) == 0)
		read_cmd(argv, cmd, line_size);
	else
	{
		write(2, ":( Command does not exist\n", 26);
		free(argv);
		free(cmd);
		prompt();
	}
	return (0);
}
