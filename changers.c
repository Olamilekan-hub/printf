#include "main.h"

unsigned int print_w(buffer_p * ans, unsigned int given,
		unsigned char flags, int w);
unsigned int print_sw(buffer_p *ans, unsigned char flags,
		int w, int p, int size);
unsigned int print_nw(buffer_p *ans, unsigned int given,
		unsigned char flags, int w);

/**
 * print_w - holds memory information for modifiers
 * @ans: a struct
 * @given: data sent to standard output
 * @flags: notice
 * @w: modify width
 *
 * Return: size of data in buffer
 */
unsigned int print_w(buffer_p *ans, unsigned int given,
		unsigned char flags, int w)
{
	unsigned int answer = 0;
	char wid = ' ';

	if (FLAG_N == 0)
	{
		for (w -= given; w > 0;)
			answer += _cpy(ans, &wid, 1);
	}

	return (answer);
}

/**
 * print_sw - holds data for modifiers
 * @ans: a struct
 * @flags: notice
 * @w: modify width
 * @p: modify precision
 * @size: size of data
 *
 * Return: size of buffer data
 */
unsigned int print_sw(buffer_p *ans, unsigned char flags,
		int w, int p, int size)
{
	unsigned int answer = 0;
	char wid = ' ';

	if (FLAG_N == 0)
	{
		wid -= (p == -1) ? size : p;
		for (; w > 0; w--)
			answer += _cpy(ans, &wid, 1);
	}

	return (answer);
}

/**
 * print_nw - trailing spaces handling
 * @ans: a struct
 * @given: size of data ready to be printed
 * @flags: notice
 * @w: width
 *
 * Return: size of data in memory.
 */
unsigned int print_nw(buffer_p *ans,  unsigned int given,
		unsigned char flags, int w)
{
	unsigned int answer = 0;
	char wid = ' ';

	if (FLAG_N == 1)
	{
		for (w -= given; w > 0; w--)
			answer += _cpy(ans, &wid, 1);
	}

	return (answer);
}
