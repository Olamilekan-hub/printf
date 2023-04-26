#include "main.h"

unsigned char handle_f(const char *flag, char *position);
unsigned char handle_l(const char *changer, char *position);
int handle_w(va_list args, const char *changer, char *position);
int handle_p(va_list args, const char *changer, char *position);
unsigned int (*handle_s(const char *required))(va_list, buffer_p *, unsigned char, int, int, unsigned char);

/**
 * handle_f- flag handling
 * @flag: notice
 * @position: keeps track of address pointer points to
 *
 * Return: data stored
 */
unsigned char handle_f(const char *flag, char *position)
{
	int i, j;
	unsigned char answer = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEGA},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*position)++;
				if (answer == 0)
					answer = flags[j].val;
				else
					answer |= flags[j].val;
				break;
			}
		}
		if (flags[j].val == 0)
			break;
	}

	return (answer);
}

/**
 * handle_l - length handling
 * @changer: modifies the length of the argument
 * @position: keeps track of address pointer points to
 *
 * Return: data stored
 */
unsigned char handle_l(const char *changer, char *position)
{
	if (*changer == 'h')
	{
		(*position)++;
		return (SHORT);
	}

	else if (*changer  == 'l')
	{
		(*position)++;
		return (LONG);
	}

	return (0);
}

/**
 * handle_w - width handling
 * @args: arguments
 * @changer: changes the precision and width
 * @position: keeps track of the address
 *
 * Return: data stored
 */
int handle_w(va_list args, const char *changer, char *position)
{
	int val = 0;

	while ((*changer >= '0' && *changer <= '9') || (*changer == '*'))
	{
		(*position)++;

		if (*changer == '*')
		{
			val = va_arg(args, int);
			if (val <= 0)
				return (0);
			return (val);
		}

		val *= 10;
		val += (*changer - '0');
		changer++;
	}

	return (val);
}

/**
 * handle_p - precision handling
 * @args: argument
 * @changer: precision modifier
 * @position: keeps track of address pointer
 *
 * Return: the data stored
 */
int handle_p(va_list args, const char *changer, char *position)
{
	int val = 0;

	if (*changer != '.')
		return (-1);

	changer++;
	(*position)++;

	if ((*changer <= '0' || *changer > '9') &&
		 *changer != '*')
	{
		if (*changer == '0')
			(*position)++;
		return (0);
	}

	while ((*changer >= '0' && *changer <= '9') ||
		   (*changer == '*'))
	{
		(*position)++;

		if (*changer == '*')
		{
			val = va_arg(args, int);
			if (val <= 0)
				return (0);
			return (val);
		}

		val *= 10;
		val += (*changer - '0');
		changer++;
	}

	return (val);
}

/**
 * handle_s - handle specification
 * @required: ensures argument is modified as specified
 *
 * Return: required specification
 */
unsigned int (*handle_s(const char *required))(va_list, buffer_p *,
		unsigned char, int, int, unsigned char)
{
	int i;
	convert_t convert[] = {
		{'c', con_c},
		{'s', con_s},
		{'d', con_d},
		{'i', con_d},
		{'%', con_per},
		{'b', con_b},
		{'u', con_u},
		{'o', con_o},
		{'x', con_x},
		{'X', con_X},
		{'S', con_S},
		{'p', con_p},
		{'r', con_r},
		{'R', con_R},
		{0, NULL}
	};

	for (i = 0; convert[i].fun; i++)
	{
		if (convert[i].required == *required)
			return (convert[i].fun);
	}

	return (NULL);
}
