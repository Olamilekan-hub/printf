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

