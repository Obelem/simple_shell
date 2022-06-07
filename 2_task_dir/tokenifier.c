#include "shell.h"

/**
 * tokenifier - create tokens
 * @cmd: pointer to input
 * @line_size: line size
 *
 */

void tokenifier(char *cmd, ssize_t line_size)
{
	char delim[] = " ";
	char *token, *cmd_buf, *cmd_param;
	int num_of_tokens = 0, num_of_chars;
	int i = 0, n;
	char **argv;

	cmd_buf = malloc(sizeof(char) * line_size);
	cmd_param = malloc(sizeof(char) * line_size);

	if (!cmd_buf || !cmd_param)
		return;

	for (n = 0; cmd[n]; )
		n++;

	n--;

	_strncpy(cmd_buf, cmd, n);
	_strncpy(cmd_param, cmd, n);
	/* get number of tokens */
	num_of_tokens = count_tok(cmd, delim);
	/* get argument vector array */
	argv = malloc(sizeof(char *) * num_of_tokens);
	if (!argv)
		return;

	free(cmd);
	token = strtok(cmd_buf, delim);
	/* initialize each argv vector element with corresponding token */
	while (token)
	{
		num_of_chars = count_tok_char(token);
		argv[i] = malloc(sizeof(char) * num_of_chars);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	read_cmd(argv, cmd_param, line_size);
}
