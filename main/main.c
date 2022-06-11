#include "shell.h"

/**
 * main - start shell
 *
 * Return: void
 */

/**
 * == changes ==
 * 1. added variable to hold exit status
 * 2. returns exit status or 0 if successful
 */
int main(void)
{
	int ret_val; /* return value */
	
	ret_val = prompt();
	
	if (ret_val != 0)
		return (ret_val);

	return (0);
}
