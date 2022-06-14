#include "shell.h"

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

	return;
}

/**
 * print_pwd - prints the current working directory
 */
void print_pwd(void)
{
	char *buf = malloc(sizeof(char) * 100);

	getcwd(buf, 100);
	
	printf("%s\n", buf); /* use our own function */
	free(buf);
	prompt();
}
