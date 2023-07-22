#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
* print_char - Print a character
* @ap: the ap list
*/
void print_char(va_list ap)
{
	char word = va_arg(ap, int);
	
	putchar(word);
}

/**
* print_string - Print a string
* @ap: the ap list
*/
void print_string(va_list ap)
{
	char *string = va_arg(ap, char *);
	
	printf("%s", string);
}

/**
* print_integer - Print an integer
* @ap: the ap list
*/
void print_integer(va_list ap)
{
	int number = va_arg(ap, int);
	
	printf("%d", number);
}

/**
* print_octal - Print an octal number
* @ap: the ap list
*/
void print_octal(va_list ap)
{
	int octal = va_arg(ap, int);
	
	printf("%i", octal);
}

/**
* _printf - Prints formatted output
* @format: the format
* Return: the size of the string
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
			void (*print_func)(va_list ap);

			switch (format[j])
			{
				case 'c':
					print_func = print_char;
					break;
				case 's':
					print_func = print_string;
					break;
				case 'd':
					print_func = print_integer;
					break;
				case 'i':
					print_func = print_octal;
					break;
				case '%':
					putchar('%');
					continue;
				default:
					putchar('%');
					putchar(format[j]);
					continue;
			}

			print_func(ap);
		}
		else
		{
			putchar(format[j]);
		}
	}
	va_end(ap);
	return (size);
}

