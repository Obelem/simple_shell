#include "shell.h"

/**
 * exit_process - exits process with status
 * @argv: tokenized input string array
 * @argc: number of tokens or argument count (argc)
 * Return: 1 on failure, 0 on success
 */
int exit_process(int argc, char **argv)
{
	int ret_val = 0, i;

	if (argc == 1)
		exit(0);

	else if (argc > 2)
	{
		write(2, ":( too many arguments\n", 22);
		prompt();
		return (1);
	}
	for (i = 0; argv[1][i]; i++)
	{
		if (isdigit(argv[1][i]) == 0)
		{
			write(2, ":( input integers only\n", 23);
			prompt();
			return (1);
		}
	}
	ret_val = atoi(argv[1]); /* atoi() used here */
	exit(ret_val);

	return (0);
}

/**
 * update_pwd - updates the present working directory
 */
void update_pwd(void)
{
	char *buf = malloc(sizeof(char) * 50);
	char *new_pwd = NULL;
	size_t pwd_len;
	int i;

	getcwd(buf, 50);
	pwd_len = strlen(buf); /* make strlen function */

	new_pwd = malloc(sizeof(char) * (pwd_len + 4));
	_strcpy(new_pwd, "PWD=");
	_strcat(new_pwd, buf);

	free(buf);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "PWD=", 4) == 0)
			break;
	}
	environ[i] = new_pwd;

}

/**
 * print_pwd - prints the current working directory
 */
void print_pwd(void)
{
	char *buf = malloc(sizeof(char) * 100);

	getcwd(buf, 100);

	printf("%s\n", buf);/* use our own function */
	free(buf);
	prompt();
}
