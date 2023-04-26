#include "main.h"

unsigned int con_d(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_b(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_u(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_o(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);

/**
 * con_d - convert argument to integer
 * @args: argument
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: data size
 * @ans: a struct
 *
 * Return: the data stored in the buffer
 */
unsigned int con_d(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	long int k, cop;
	unsigned int answer = 0, track = 0;
	char y, space = ' ', neg = '-', plus = '+';

	if (length == LONG)
	{
		k = va_arg(args, long int);
	}
	else
	{
		k = va_arg(args, long int);
	}
	if (length == SHORT)
	{
		k = (short)k;
	}
	if (FLAG_S == 1 && k >= 0)
	{
		answer += _cpy(ans, &space, 1);
	}
	if (p <= 0 && FLAG_N == 0)
	{
		if (k == LONG_MIN)
		{
			track += 19;
		}
		else
		{
			for (cop = (k < 0) ? -k : k; cop > 0; cop /= 10)
			{
				track++;
			}
		}
			track += (k == 0) ? 1 : 0;
			track += (k < 0) ? 1 : 0;
			track += (FLAG_P == 1 && k >= 0) ? 1 : 0;
			track += (FLAG_S == 1 && k >= 0) ? 1 : 0;

			if (FLAG_Z == 1 && FLAG_P == 1 && k >= 0)
			{
				answer += _cpy(ans, &neg, 1);
			}
			if (FLAG_Z == 1 && k < 1)
			{
				answer += _cpy(ans, &neg, 1);
			}
			y = (FLAG_Z == 1) ? '0' : ' ';
			for (w -= track; w > 0; w--)
			{
				answer += _cpy(ans, &y, 1);
			}
	}

	if (FLAG_Z == 0 && k < 0)
	{
		answer += _cpy(ans, &neg, 1);
	}
	if (FLAG_Z == 0 && (FLAG_P == 1 && k >= 0))
	{
		answer += _cpy(ans, &plus, 1);
	}
	if (!(k == 0 && p == 0))
	{
		answer += con_sb(ans, k, "0123456789", flags, 0, p);
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * con_b - convert argument to binary
 * @args: argument
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: data size
 * @ans: a struct
 *
 * Return: the data stored in the buffer
 */
unsigned int con_b(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)length;

	return (con_ub(ans, num, "01", flags, w, p));
}

/**
 * con_o - convert argument to octal
 * @args: argument
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: data size
 * @ans: a struct
 *
 * Return: the data stored in the buffer
 */
unsigned int con_o(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	unsigned long int num;
	unsigned int answer = 0;
	char zero = '0';

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
		answer += _cpy(ans, &zero, 1);
	}
	if (!(num == 0 && p == 0))
	{
		answer += con_ub(ans, num, "01234567", flags, w, p);
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * con_u - convert argument to decimal
 * @args: argument
 * @flags: notices
 * @w: width
 * @p: precision
 * @length: data size
 * @ans: a struct
 *
 * Return: the data stored in the buffer
 */
unsigned int con_u(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length)
{
	unsigned long int num;
	unsigned int answer = 0;

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
	if (!(num == 0 && p == 0))
	{
		answer += con_ub(ans, num, "0123456789", flags, w, p);
	}
	answer += print_nw(ans, answer, flags, w);

	return (answer);
}
