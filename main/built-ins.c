#include "shell.h"

/**
 * exit_process - exits process with status
 * @argv: tokenized input string array
 * @argc: number of tokens or argument count (argc)
 * Return: 1 on failure, 0 on success
 */

/**
 * Hello Frank -> PLEASE, TAKE NOTE!!
 * I used atoi() to convert from ascii to integer, we have to create ours
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

int _setenv(int argc, char **argv)
{
	int i, j, env_len = 0;
	char **my_environ = environ;
	

	/* get length of environ variable */
	while (my_environ[env_len])
		env_len++;

	printf("%d\n", env_len);
	if (argc != 3)
	{
		write(2, ":( format -> setenv VARIABLE VALUE\n", 35);
		prompt();
		return (1);
	}
	for (i = 0; my_environ[i]; i++)
	{
		for (j = 0; argv[1][j]; j++)
		{
			if (argv[1][j] == '=')
			{
				write(2, ":( shouldn't contain '='\n", 25);
				prompt();
				return -1;
			}
			if (argv[1][j] != my_environ[i][j])
				break;
		}
		if (argv[1][j] == '\0')
		{
			_strcat(argv[1], "=");
			_strcat(argv[1], argv[2]);
			my_environ[i] = argv[1];
			prompt();
			return 0;
		}
	}
	/* if no match, add new env variable below */
	

	prompt();
	return -1;
}

/**
 * change_dir - built-in cd command
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success, -1 for failure
 */
int change_dir(int argc, char **argv)
{
	int val, i;
	char *env_names[] = {"HOME=", "PWD="};
	char *buf = malloc(sizeof(char) * 50);

	if (argc > 2)
	{
		write(2, ":( too many arguments\n", 22);
		prompt();
		return (-1);
	}
	if (argc == 2)
	{
		val = chdir(argv[1]);
		if (val == -1)
			write(2, ":( directory does not exist\n", 28);
	
		update_pwd();

		prompt();
		return 0;
	}
	if (argc == 1)
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp(environ[i], env_names[0], 5) == 0)
				break;
		}
		_strcpy(buf, &environ[i][5]);
		chdir(buf);
		
		update_pwd();

		free(buf);
		prompt();
	}
	return (0);
}

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


void print_pwd(void)
{
	char *buf = malloc(sizeof(char) * 100);

	getcwd(buf, 100);
	
	printf("%s\n", buf); /* use our own function */
	free(buf);
	prompt();
}
