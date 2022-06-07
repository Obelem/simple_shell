#include "shell.h"

/**
 * count_tok - get number of token
 * @cmd: pointer to input
 * @delim: delimiter
 *
 * Return: number of token
 */

int count_tok(char *cmd, char *delim)
{
	int n = 0;
	char *token;

	token = strtok(cmd, delim);

	while (token)
	{
		n++;
		token = strtok(NULL, delim);
	}

	free(token);
	return (n);
}

/**
 * count_tok_char - count number of character in a token
 * @token: pointer to token
 *
 * Return: number of char
 */

int count_tok_char(char *token)
{
	int n;

	for (n = 0; token[n]; )
		n++;
	return (n);
}

/**
 * add_to_argv - add token to argv
 * @argv: pointer to token pointers
 * @token: pointer to token
 * @i: index of token
 * @n: number of char in token
 * @delim: delimiter
 *
 * Return: void
 */

void add_to_argv(char **argv, char *token, int i, int n, char *delim)
{
	argv[i] = malloc(sizeof(char) * n);
	strcpy(argv[i], token);
	token = strtok(NULL, delim);
}
