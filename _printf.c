#include "main.h"
void print_storage(char storage[], int *store_pos);

/**
 * _printf - print stored data
 * @format: the required format
 *
 * Return: the data in the required format
 */

int _printf(const char *format, ...)
{
	int n, ans = 0, ans_given = 0;
	int flag, width, precision, size, store_pos;

	va_list list;
	char storage[BUFFER_SIZE];

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			storage[store_pos++] = format[n];
			if (store_pos == BUFFER_SIZE)
			{
				print_storage(storage, &store_pos);
			}
			ans_given++;
		}
		else
		{
			print_storage(storage, &store_pos);
			flag = bring_flag(format, &n);
			width = bring_width(format, &n, list);
			precision = bring_precision(format, &n, list);
			size = bring_size(format, &n);
			++n;
			ans = admin(format, &n, list, storage, flag, width, precision, size);
			if (ans == -1)
			{
				return (-1);
			}
			ans_given += ans;
		}
	}
	print_storage(storage, &store_pos);
	va_end(list);
	return (ans_given);
}

/**
 * print_storage - prints data stored in buffer
 * @storage: data stored in memory location
 * @store_pos: the present position on the array
 */

void print_storage(char storage[], int *store_pos)
{
	if (*store_pos > 0)
	{
		write(1, &storage[0], *store_pos);
		*store_pos = 0;
	}
}
