#include "main.h"

/****to print character***/

/**
 * character - print a character
 * @flag: important notices
 * @width: breadth
 * @precision: accuracy
 * @size: coverage
 * @types: arguments
 * @storage: data storage
 * Return: Characters
 */

int character(va_list types, char storage[], int flag, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (writechar(a, storage, flag, width, precision, size));
}
/****to print a string***/
/**
 * string - print a character
 * @flag: important notices
 * @width: breadth
 * @precision: accuracy
 * @size: coverage
 * @types: arguments
 * @storage: data storage
 * Return: Characters
 */

int string(va_list types, char storage[], int flag, int width, int precision, int size)
{
	int leng = 0, n;
	char *stri = va_arg(types, char *);

	UNUSED(storage);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (stri == NULL)
	{
		stri = "(null)";
		if (precision >= 6)
		{
			stri = "     ";
		}
	}
	while (stri[leng] != '\0')
	{
		leng++;
	}
	if (precision >= 0 && precision < leng)
	{
		leng = precision;
	}
	if (width > leng)
	{
		if (flag & MINUS)
		{
			write(1, &stri[0], leng);
			for (n =  width - leng; n > 0; n--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (n = width - leng; n > 0; n--)
			{
				write(1, " ", 1);
			}
			write(1, &stri[0], leng);
			return (width);
		}
	}
	return (write(1, stri, leng));
}

/****to print a percent sign***/
/**
 * percentage - print the percentage sign
 * @flag: important notices
 * @width: breadth
 * @precision: accuracy
 * @size: coverage
 * @types: arguments
 * @storage: data storage
 * Return: Characters
 */

int percentage(va_list types, char storage[], int flag, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(storage);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/****to print integer***/
/**
 * integer - print the percentage sign
 * @flag: important notices
 * @width: breadth
 * @precision: accuracy
 * @size: coverage
 * @types: arguments
 * @storage: data storage
 * Return: Characters
 */

int integer(va_list types, char storage[], int flag, int width, int precision, int size)
{
	int n = BUFFER_SIZE - 2;
	int is_neg = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convertsizenumber(m, size);

	if (m == 0)
	{
		storage[n--] = '0';
	}

	storage[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)m;
	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_neg = 1;
	}
	while (num > 0)
	{
		storage[n--] = (num % 10) + '0';
		num /= 10;
	}
	n++;

	return (writenum(is_neg, n, storage, flag, width, precision, size));
}

/****to print binary***/
/**
 * binary - print the percentage sign
 * @flag: important notices
 * @width: breadth
 * @precision: accuracy
 * @size: coverage
 * @types: arguments
 * @storage: data storage
 * Return: Characters
 */

int binary(va_list types, char storage[], int flag, int width, int precision, int size)
{
	unsigned int m, p, n, add;
	unsigned int b[32];
	int note;

	UNUSED(storage);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	p = 2147483648;
	b[0] = m / p;
	for (n = 1; n < 32; n++)
	{
		p /= 2;
		b[n] = (m / p) % 2;
	}
	for (n = 0, add = 0, note = 0; n < 32; n++)
	{
		add += b[n];
		if (add || n == 31)
		{
			char y = '0' + b[n];

			write(1, &y, 1);
			note++;
		}
	}
	return (note);
}
