#include "shell.h"

/**
 * file_path - adds path and checks if command exists
 * @cmd: command input
 * @line_size: command length
 */
void file_path(char **argv, char *cmd, ssize_t line_size)
{
	int len = 0;
	char *buf = NULL;
	struct stat cmd_stat;

	while (argv[0][len])
		len++;
	
	if (argv[0][0] != '/')
	{
		buf = malloc(sizeof(char) * len);
		
		/* copy text in argv[0] to buf */
		_strncpy(buf, argv[0], len);
		free(argv[0]);

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
}
