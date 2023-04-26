#include "main.h"

unsigned int con_c(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_per(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_p(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);

/**
 * con_c - converts to char
 * @args: arguments
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: length of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_c(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	char h;
	unsigned int answer = 0;

	(void)p;
	(void)length;

	h = va_arg(args, int);

	answer += print_w(ans, answer, flags, w);
	answer += _cpy(ans, &h, 1);
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * con_per - store the percent sign
 * @args: arguments
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: length of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_per(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	char percent = '%';
	unsigned int answer = 0;

	(void)args;
	(void)p;
	(void)length;

	answer += print_w(ans, answer, flags, w);
	answer += _cpy(ans, &percent, 1);
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * con_p - convert address to hexadecimal
 * @args: arguments
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: length of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_p(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	char *null = "(nil)";
	unsigned long int adr;
	unsigned int answer = 0;

	(void)length;

	adr = va_arg(args, unsigned long int);
	if (adr == '\0')
	{
		return (_cpy(ans, null, 5));
	}
	flags |= 32;
	answer += con_ub(ans, adr, "0123456789abcdef", flags, w, p);
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}
