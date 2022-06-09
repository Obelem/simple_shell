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
 * assign_lineptr - Reassigns/modify lineptr with buffer from _getline
 * @lineptr: Buffer that stores strin input
 * @n: lineptr size
 * @buffer: The string to assign to lineptr.
 * @b: size of buffer from _getline.
 * 
 * Return: void
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 100)
			*n = b;
		else
			*n = 100;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 100)
			*n = b;
		else
			*n = 100;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input; 
	ssize_t to_return;
	char c = ' ', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 100); /* default size of 100 */
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 100)
			buffer = realloc(buffer, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	to_return = input;
	if (r != 0)
		input = 0;
	return (ret);
}
