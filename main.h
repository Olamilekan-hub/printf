#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAG */
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

/* SIZE */
#define LONG 2
#define SHORT 1

/**
 * struct fmat - structure
 * @fmat: required format
 * @fun: similar function
 */
struct fmat
{
	char fmat;
	int (*fun)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmat fma_t - structure
 * @fmat: required format
 * @fma_t: similar structure
 */
typedef struct fmat fma_t;

int _printf(const char *format, ...);
int admin(const char *fmat, int *n,
va_list list, char storage[], int flag, int width, int precision, int
size);

/* FUNCTIONS */
int character(va_list types, char storage[],
int flag, int width, int precision, int size);
int string(va_list types, char storage[],
int flag, int width, int precision, int size);
int percentage(va_list types, char storage[],
int flag, int width, int precision, int size);
int integer(va_list types, char storage[],
int flag, int width, int precision, int size);
int binary(va_list types, char storage[],
int flag, int width, int precision, int size);
int unsignd(va_list types, char storage[],
int flag, int width, int precision, int size);
int octal(va_list types, char storage[],
int flag, int width, int precision, int size);
int hexadecimal(va_list types, char storage[],
int flag, int width, int precision, int size);
int hexaupper(va_list types, char storage[],
int flag, int width, int precision, int size);
int hexa(va_list types, char map_to[],
char storage[], int flag, char flag_ch, int width, int precision, int
size);
int nonprintable(va_list types, char storage[],
int flag, int width, int precision, int size);
int pointer(va_list types, char storage[],
int flag, int width, int precision, int size);
int bring_flag(const char *format, int *n);
int bring_width(const char *format, int *n, va_list list);
int bring_precision(const char *format, int *n, va_list list);
int bring_size(const char *format, int *n);
int reverse(va_list types, char storage[],
int flag, int width, int precision, int size);
int rot13(va_list types, char storage[],
int flag, int width, int precision, int size);
int writechar(char c, char storage[],
int flag, int width, int precision, int size);
int writenum(int is_positive, int ind, char storage[],
int flag, int width, int precision, int size);
int writenumber(int ind, char bff[], int flag, int width, int precision,
int length, char padd, char extra_c);
int writepointer(char storage[], int ind, int length,
int width, int flag, char padd, char extra_c, int padd_start);
int writeunsigned(int is_negative, int ind, char storage[], int flag, int width, int precision, int size);
int isprintable(char);
int hexacode(char, char[], int);
int itdigit(char);
long int convertsizenumber(long int num, int size);
long int convertsizeunsigned(unsigned long int num, int size);
#endif /* MAIN_H */
