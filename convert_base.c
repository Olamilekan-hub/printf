#include "main.h"

unsigned int con_sb(buffer_p *ans, long int num, char *base, unsigned char flags, int w, int p);
unsigned int con_ub(buffer_p *ans, unsigned long int num, char *base, unsigned char flags, int w, int p);

/**
 * con_sb - convert to a number in a given base
 * @ans: a struct
 * @num: the number to be converted
 * @base: the needed base
 * @flags: notices
 * @w: the width
 * @p: the precision
 *
 * Return: date stored in buffer
 */
unsigned int con_sb(buffer_p *ans, long int num, char *base, unsigned char flags, int w, int p)
{
	int size;
	char d, y = '0';
	unsigned int answer = 1;

	for (size = 0; *(base + size);)
	{
		size++;
	}
	if (num >= size || num <= -size)
	{
		answer += con_sb(ans, num / size, base, flags, w - 1, p - 1);
	}
	else
	{
		for (; p > 1; p--, w--)
		{
			answer += _cpy(ans, &y, 1);
		}
		if (FLAG_N == 0)
		{
			y = (FLAG_Z == 1) ? '0' : ' ';
			for (; w > 1; w--)
			{
				answer += _cpy(ans, &y, 1);
			}
		}
	}

	d = base[(num < 0 ? -1 : 1) * (num % size)];
	_cpy(ans, &d, 1);

	return (answer);
}

/**
 * con_ub - converts unsigned number into a base of choice
 * @ans: a struct
 * @num: the number to convert
 * @base: the desired base
 * @flags: notices
 * @w: width
 * @p: precision
 *
 * Return: the data stored in buffer
 */
unsigned int con_ub(buffer_p *ans, unsigned long int num, char *base, unsigned char flags, int w, int p)
{
	unsigned int size, answer = 1;
	char d, y = '0', *l = "0x";

	for (size = 0; *(base + size);)
	{
		size++;
	}
	if (num >= size)
	{
		answer += con_ub(ans, num / size, base, flags, w - 1, p - 1);
	}
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			w -= 2;
			p -= 2;
		}
		for (; p > 1; p--, w--)
		{
			answer += _cpy(ans, &y, 1);
		}
		if (FLAG_N == 0)
		{
			y = (FLAG_Z == 1) ? '0' : ' ';
			for (; w > 1; w--)
			{
				answer += _cpy(ans, &y, 1);
			}
		}
		if (((flags >> 5) & 1) == 1)
		{
			answer += _cpy(ans, l, 2);
		}
	}

	d = base[(num % size)];
	_cpy(ans, &d, 1);

	return (answer);
}
