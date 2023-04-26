#include "main.h"

unsigned int con_s(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_S(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_r(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_R(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);

/**
 * convert_s - Convert argument to string
 * @args: the argument
 * @flags: notice.
 * @w: width
 * @p: precision
 * @length: size of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_s(va_list args, buffer_p *ans,
		unsigned char flags, int w, int p, unsigned char length)
{
	char *str, *null = "(null)";
	int size;
	unsigned int answer = 0;

	(void)flags;
	(void)length;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_cpy(ans, null, 6));

	for (size = 0; *(str + size);)
		size++;

	answer += print_sw(ans, flags, w, p, size);

	p = (p == -1) ? size : p;
	while (*str != '\0' && p > 0)
	{
		answer += _cpy(ans, str, 1);
		p--;
		str++;
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * convert_S - convert argument to string
 * @args: the argument
 * @flags: notice
 * @w: width
 * @p: precision
 * @length: size of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_S(va_list args, buffer_p *ans,
		unsigned char flags, int w, int p, unsigned char length)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, position;
	unsigned int answer = 0;

	(void)length;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_cpy(ans, null, 6));

	for (size = 0; str[size];)
		size++;

	answer += print_sw(ans, flags, w, p, size);

	p = (p == -1) ? size : p;
	for (position = 0; *(str + position) != '\0' && position < p; position++)
	{
		if (*(str + position) < 32 || *(str + position) >= 127)
		{
			answer += _cpy(ans, hex, 2);
			if (*(str + position) < 16)
				answer += _cpy(ans, &zero, 1);
			answer += con_ub(ans, *(str + position),
						 "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		answer += _cpy(ans, (str + position), 1);
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * convert_r - reverse the argument
 * @args: argument
 * @flags: notice
 * @w: width
 * @p: precision
 * @length: size of answer
 * @ans: a struct
 *
 * Return: data stored in the bufffer
 */
unsigned int con_r(va_list args, buffer_p *ans,
		unsigned char flags, int w, int p, unsigned char length)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int answer = 0;

	(void)flags;
	(void)length;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_cpy(ans, null, 6));

	for (size = 0; *(str + size);)
		size++;

	answer += print_sw(ans, flags, w, p, size);

	end = size - 1;
	p = (p == -1) ? size : p;
	for (i = 0; end >= 0 && i < p; i++)
	{
		answer += _cpy(ans, (str + end), 1);
		end--;
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}

/**
 * convert_R - Convert argument to ROT13
 * @args: argument.
 * @flags: notice
 * @w: width
 * @p: precision
 * @length: size of answer
 * @ans: a struct
 *
 * Return: data stored in buffer
 */
unsigned int con_R(va_list args, buffer_p *ans,
		unsigned char flags, int w, int p, unsigned char length)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int answer = 0;

	(void)flags;
	(void)length;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_cpy(ans, null, 6));

	for (size = 0; *(str + size);)
		size++;

	answer += print_sw(ans, flags, w, p, size);

	p = (p == -1) ? size : p;
	for (i = 0; *(str + i) != '\0' && i < p; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				answer += _cpy(ans, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			answer += _cpy(ans, (str + i), 1);
	}

	answer += print_nw(ans, answer, flags, w);

	return (answer);
}
