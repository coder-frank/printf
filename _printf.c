#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
* print_char - Print a character
*/
void print_char(va_list ap)
{
	char word = va_arg(ap, int);
	putchar(word);
}

/**
* print_string - Print a string
*/
void print_string(va_list ap)
{
	char *string = va_arg(ap, char *);
	printf("%s", string);
}

/**
* print_integer - Print an integer
*/
void print_integer(va_list ap)
{
	int number = va_arg(ap, int);
	printf("%d", number);
}

/**
* print_octal - Print an octal number
*/
void print_octal(va_list ap)
{
	int octal = va_arg(ap, int);
	printf("%i", octal);
}

/**
* _printf - Prints formatted output
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int size = 0, j;

	va_start(ap, format);
	if (format == NULL)
		return (-1);

	size = strlen(format);
	for (j = 0; j < size; j++)
	{
		if (format[j] == '\n')
			size--;
			if (format[j] == '%')
			{
				j++;
				switch (format[j])
				{
					case 'c':
						print_char(ap);
						break;
					case 's':
						print_string(ap);
						break;
					case 'd':
						print_integer(ap);
						break;
					case 'i':
						print_octal(ap);
						break;
					case '%':
						putchar('%');
						break;
					default:
						putchar('%');
						putchar(format[j]);
						break;
				}
			}
			else
			{
				putchar(format[j]);
			}
	}
	va_end(ap);
	return (size);
}

