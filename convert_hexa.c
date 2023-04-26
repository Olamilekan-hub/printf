#include "main.h"

unsigned int con_x(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_X(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);

/**
 * con_x - convert number into hexadecimal in lowercase
 * @args: arguments
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: how long is answer
 *
 * Return: the data stored
 */
unsigned int con_x(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	unsigned long int num;
	unsigned int answer = 0;
	char *l = "0x";

	if (length == LONG)
	{
		num = va_arg(args, unsigned long int);
	}
	else
	{
		num = va_arg(args, unsigned int);
	}
	if (length == SHORT)
	{
		num = (unsigned short)num;
	}
	if (FLAG_H == 1 && num != 0)
	{
		answer += _cpy(ans, l, 2);
	}
	if (!(num == 0 && p == 0))
	{
		answer += con_ub(ans, num, "0123456789abcdef", flags, w, p);
	}
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * con_X - convert number into hexadecimal in uppercase
 * @args: arguments
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: how long is answer
 *
 * Return: the data stored
 */
unsigned int con_X(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	unsigned long int num;
	unsigned int answer = 0;
	char *l = "0X";

	if (length == LONG)
	{
		num = va_arg(args, unsigned long);
	}
	else
	{
		num = va_arg(args, unsigned int);
	}
	if (length == SHORT)
	{
		num = (unsigned short)num;
	}
	if (FLAG_H == 1 && num != 0)
	{
		answer += _cpy(ans, l, 2);
	}
	if (!(num == 0 && p == 0))
	{
		answer += con_ub(ans, num, "0123456789ABCDEF", flags, w, p);
	}
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}
