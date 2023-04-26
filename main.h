#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


/* flag */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEGA 16
#define FLAG_P (flags & 1)
#define FLAG_S ((flags >> 1) & 1)
#define FLAG_H ((flags >> 2) & 1)
#define FLAG_Z ((flags >> 3) & 1)
#define FLAG_N ((flags >> 4) & 1)

/* length */
#define SHORT 1
#define LONG 2


/**
 * struct buffer_m - define new struct
 * @buffer: a pointer to the address of an array
 * @begin: pointer to start of buffer
 * @length: span of stored data
 */
typedef struct buffer_m
{
	char *buffer;
	char *begin;
	unsigned int length;
} buffer_p;

/**
 * struct convert_s - define new struct
 * @required: the specified format
 * @fun: pointer to specified format function
 */
typedef struct convert_s
{
	unsigned char required;
	unsigned int(*fun)(va_list, buffer_p *, unsigned char, int, int, unsigned char);
} convert_t;

/**
 * struct flag_s - define new struct
 * @flag: a notice that shows up
 * @val: weight of flag
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char val;
} flag_t;

int _printf(const char *format, ...);

/* conversion functions */
unsigned int con_c(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_s(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_d(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_per(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_b(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_u(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_o(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_x(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_X(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_S(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_p(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_r(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);
unsigned int con_R(va_list args, buffer_p *ans, unsigned char flags, int w, int p, unsigned char length);

/* Handle */
unsigned char handle_f(const char *flags, char *position);
unsigned char handle_l(const char *changer, char *position);
int handle_w(va_list args, const char *changer, char *position);
int handle_p(va_list args, const char *changer, char *position);
unsigned int(*handle_s(const char *required))(va_list, buffer_p *, unsigned char, int, int, unsigned char);

/* changers */
unsigned int print_w(buffer_p *ans, unsigned int given, unsigned char flags, int w);
unsigned int print_sw(buffer_p *ans, unsigned char flags, int w, int p, int size);
unsigned int print_nw(buffer_p *ans, unsigned int given, unsigned char flags, int w);

/* helps */
buffer_p *init_b(void);
void free_b(buffer_p *ans);
unsigned int _cpy(buffer_p *ans, const char *source, unsigned int m);
unsigned int con_sb(buffer_p *ans, long int num, char *base, unsigned char flags, int w, int p);
unsigned int con_ub(buffer_p *ans, unsigned long int num, char *base, unsigned char flags, int w, int p);

#endif /* MAIN_H */
