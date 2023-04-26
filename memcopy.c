#include "main.h"

unsigned int _cpy(buffer_p *ans, const char *source, unsigned int n);
void free_b(buffer_p *ans);
buffer_p *init_b(void);

/**
 * _cpy - copy the content of memory specified
 * @ans: a struct
 * @source: Memory from which data is copied
 * @n: size of memory.
 *
 * Return: memory size to be copied.
 */
unsigned int _cpy(buffer_p *ans, const char *source, unsigned int n)
{
	unsigned int position;

	for (position = 0; position < n; position++)
	{
		*(ans->buffer) = *(source + position);
		(ans->length)++;

		if (ans->length == 1024)
		{
			write(1, ans->begin, ans->length);
			ans->buffer = ans->begin;
			ans->length = 0;
		}

		else
			(ans->buffer)++;
	}

	return (n);
}

/**
 * free_b - memory management
 * @ans: free the buffer
 */
void free_b(buffer_p *ans)
{
	free(ans->begin);
	free(ans);
}

/**
 * init_b - start struct
 *
 * Return: pointer
 */
buffer_p *init_b(void)
{
	buffer_p *ans;

	ans = malloc(sizeof(buffer_p));
	if (ans == NULL)
		return (NULL);

	ans->buffer = malloc(sizeof(char) * 1024);
	if (ans->buffer == NULL)
	{
		free(ans);
		return (NULL);
	}

	ans->begin = ans->buffer;
	ans->length = 0;

	return (ans);
}
