#include "shell.h"

/**
 * _setenv - sets the environment variables
 * @argc: argument count
 * @argv: command (tokenified)
 * Return: val
 */
int _setenv(int argc, char **argv)
{
	int val, env_len = 0;

	if (!my_environ)
		my_environ = environ;

	while (my_environ[env_len])
		env_len++;

	if (argc != 3)
	{
		write(2, ":( format -> setenv VARIABLE VALUE\n", 35);
		prompt();
		return (1);
	}
	val = modify_env(argv);

	if (val != 1)
		return (val);

	/* if no match, create new env variable below */
	val = create_env(argv, ++env_len);

	prompt();
	return (val);
}

/**
 * modify_env - checks if env variable can be modified
 * @argv: argument count
 * Return: -1 if string contains '=', 0 on success, 1 if no match
 */
int modify_env(char **argv)
{
	int i, j;

	for (i = 0; my_environ[i]; i++)
	{
		for (j = 0; argv[1][j]; j++)
		{
			if (argv[1][j] == '=')
			{
				write(2, ":( shouldn't contain '='\n", 25);
				prompt();
				return (-1);
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
			return (0);
		}
	}
	return (1);/* no match, create the variable */
}

/**
 * create_env - adds a new env variable
 * @argv: command
 * @env_len: environment variable array
 * Return: 1, always success
 */
int create_env(char **argv,  int env_len)
{
	int i;
	char **buf;
	size_t size;

	buf = malloc(sizeof(char *) * env_len);

	for (i = 0; my_environ[i]; i++)
	{
		size = strlen(my_environ[i]);
		buf[i] = malloc(sizeof(char) * size);
		_strcpy(buf[i], my_environ[i]);
	}
	_strcat(argv[1], "=");
	_strcat(argv[1], argv[2]);

	buf[i++] = argv[1];
	buf[i] = NULL;

	environ = buf;
	my_environ = buf;

	return (1);
}

/**
 * _unsetenv - deletes an environment variable
 * @argv: tokenized command
 * Return: int
 */
int _unsetenv(char **argv)
{
	int env_len, i, j, checker = 0;
	size_t var_len;
	char **buf;

	if (!my_environ)
		my_environ = environ;

	for (env_len = 0; my_environ[env_len]; )
		env_len++;
	var_len = strlen(argv[1]);
	for (i = 0; my_environ[i]; i++)
	{
		if (_strncmp(my_environ[i], argv[1], var_len) == 0)
		{
			checker = 1;
			break;
		}
	}
	if (checker != 1)
	{
		prompt();
		return (0);
	}
	buf = malloc(sizeof(char *) * (env_len - 1));
	checker = i;
	for (i = 0, j = 0; my_environ[i]; i++, j++)
	{
		if (checker == i)
			i++;
		if (!my_environ[i])
			break;
		var_len = strlen(my_environ[i]);
		buf[j] = malloc(sizeof(char) * var_len);
		_strcpy(buf[j], my_environ[i]);
	}
	buf[j] = NULL;
	environ = buf;
	my_environ = buf;
	prompt();
	return (0);
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
		return (0);
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
