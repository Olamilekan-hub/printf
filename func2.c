#include "main.h"

/****to print unsigned number***/
/**
 * unsignd - print unsigned integer
 * @size: length
 * @width: breadth
 * @flag: notice
 * @precision: accuracy
 * @storage: data
 * @types: arguments
 * Return: answer
 */

int unsignd(va_list types, char storage[], int flag, int width, int precision, int size)
{
	int n = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convertsizeunsigned(num, size);

	if (num == 0)
	{
		storage[i--] = '0';
	}
	storage[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		storage[n--] = (num % 10)+ '0';
		num /= 10;
	}
	n++;
	
	return (writeunsigned(0, n, storage, flag, width, precision, size));
}

/****print unsigned number in octal format***/

/**
 * octal - print unsigned number in octal format
  * @size: length
 * @width: breadth
 * @flag: notice
 * @precision: accuracy
 * @storage: data
 * @types: arguments
 * Return: answer
 */

int octal(va_list types, char storage[], int flag, int width, int precision, int size)
{
	int n = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(width);

	num = convertsizeunsigned(num, size);

	if (num == 0)
	{
		storage[n--] = '\0';
	}
	storage[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		storage[n--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & HASH && init_num != 0)
	{
		storage[n--] = '0';
	}
	n++;
	
	return (writeunsigned(0, n, storage, flag, width, precision, size));
}


