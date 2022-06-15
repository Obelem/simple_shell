#include "shell.h"

/**
 * tokenifier - create tokens
 * @cmd: pointer to input
 * @line_size: line size
 *
 */

/**
 * == changes ==
 * 1. changed return type to int to cater for exit status
 * 2. returns 1 on failure or the return value from file_path() on success
 */
int tokenifier(char *cmd, ssize_t line_size)
{
	char delim[] = " ";
	char *token, *cmd_buf, *cmd_param;
	int num_of_tokens = 0, num_of_chars;
	int i = 0, n;
	char **argv;

	/* only cmd_param copy would not be polluted by strtok */
	cmd_buf = malloc(sizeof(char) * line_size);
	cmd_param = malloc(sizeof(char) * line_size);

	if (!cmd_buf || !cmd_param)
		return (1);

	for (n = 0; cmd[n]; )
		n++;
	n--;
	_strncpy(cmd_buf, cmd, n);
	_strncpy(cmd_param, cmd, n);

	/* use cmd to get number of tokens for creating argv*/
	num_of_tokens = count_tok(cmd, delim);
	argv = malloc(sizeof(char *) * num_of_tokens);
	if (!argv)
		return (1);
	free(cmd);

	/* use cmd_buf to get argument vector array & corresponding elements */
	token = strtok(cmd_buf, delim);
	for ( ; token; i++)
	{
		num_of_chars = count_tok_char(token);
		argv[i] = malloc(sizeof(char) * num_of_chars);
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(cmd_buf);
	return (file_path(argv, num_of_tokens, cmd_param, line_size));
}
