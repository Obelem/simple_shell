#include "shell.h"

/**
 * main - start shell
 *
 * Return: void
 */


int main(void)
{
	int ret_val;

	ret_val = prompt();
	if (ret_val != 0)
		return (ret_val);

	return (0);
}
