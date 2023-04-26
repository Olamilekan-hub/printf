#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: the chardacter to print
 * Return: 0 on success and -1 for error 
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
