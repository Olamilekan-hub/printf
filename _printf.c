#include "main.h"

void clear(va_list args, buffer_p *ans);
int tryit(const char *format, va_list args, buffer_p *ans);
int _printf(const char *format, ...);

/**
 * clear - clears workspace
 * @args: arguments
 * @ans: a struct
 */
void clear(va_list args, buffer_p *ans)
{
	va_end(args);
	write(1, ans->begin, ans->length);
	free_b(ans);
}

/**
 * tryit - scans format
 * @format: to be printed
 * @ans: a struct
 * @args: arguments
 *
 * Return: data stored
 */
int tryit(const char *format, va_list args, buffer_p *ans)
{
	int n, w, p, answer = 0;
	char hold;
	unsigned char flags, length;
	unsigned int (*v)(va_list, buffer_p *, unsigned char, int, int, unsigned char);

	for (n = 0; *(format + n); n++)
	{
		length = 0;
		if (*(format + n) == '%')
		{
			hold = 0;
			flags = handle_f(format + n + 1, &hold);
			w = handle_w(args, format + n + hold + 1, &hold);
			p = handle_p(args, format + n + hold + 1, &hold);
			length = handle_l(format + n + hold + 1, &hold);
			v = handle_s(format + n + hold + 1);
			if (v != NULL)
			{
				n += hold + 1;
				answer += v(args, ans, flags, w, p, length);
				continue;
			}
			else if (*(format + n + hold + 1) == '\0')
			{
				answer = -1;
				break;
			}
		}
		answer += _cpy(ans, (format + n), 1);
		n += (length != 0) ? 1 : 0;
	}
	clear(args, ans);
	return (answer);
}

/**
 * _printf - prints in specified format
 * @format: the information to be printed
 *
 * Return: the data stored
 */
int _printf(const char *format, ...)
{
	buffer_p *ans;
	va_list args;
	int answer;

	if (format == NULL)
	{
		return (-1);
	}
	ans = init_b();
	if (ans == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	answer = tryit(format, args, ans);

	return (answer);
}
