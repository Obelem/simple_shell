#include "shell.h"

void tokenifier (char *cmd, ssize_t line_size)
{
	char delim[] = " ";
	char *token, *cmd_buf, *cmd_param;
	int num_of_tokens = 0;
	int i = 0, n;
	char **argv;

	cmd_buf = malloc(sizeof(char) * line_size);
	cmd_param = malloc(sizeof(char) * line_size);

	if (!cmd_buf || !cmd_param)
		return;
	for (n = 0; cmd[n]; n++);
	n--;

	strncpy(cmd_buf, cmd, n);
	strncpy(cmd_param, cmd, n);
	
	/* get number of tokens */
	token = strtok(cmd, delim);
	while (token)
	{
		num_of_tokens++;
		token = strtok(NULL, delim);
	}

	/* get argument vector array */
	argv = malloc(sizeof(char *) * num_of_tokens); 
	if (!argv)
		return;

	free(token);
	free(cmd);
	token = strtok(cmd_buf, delim);

	/* initialize each argv vector element with corresponding token */
	while (token)
	{
		for (num_of_tokens = 0; token[num_of_tokens]; )
			num_of_tokens++;

		argv[i] = malloc(sizeof(char) * num_of_tokens);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	read_cmd(argv, cmd_param, line_size);
}
