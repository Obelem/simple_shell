#include "shell.h"

/**
 * _strncpy - copies n characters of string pointed
 *            to by src, to the buffer pointed by dest.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 * @n: number of char to copy
 *
 * Return: Pointer to dest
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
