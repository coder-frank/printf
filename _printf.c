#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * _printf - prints any character
 * @format: The format
 * Return: The size of the string
*/
int _printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int i;
	int size;

	size = strlen(format);
	for (i = 0; i < size; i++)
	{
		if (format[i] == '\n')
			size--;
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					char word = va_arg(ap, int);
					printf("%c", word);
					break;
				case 's':
					char *string = va_arg(ap, char *);
					printf("%s", string);
					break;
				case 'd':
					int number = va_arg(ap, int);
					printf("%d", number);
					break;
				case 'i':
					int octal = va_arg(ap, int);
					printf("%i", octal);
					break;
				case 'u':
					unsigned num = va_arg(ap, unsigned);
					printf("%u", num);
					break;
				case 'o':
					unsigned int octa = va_arg(ap, unsigned int);
					printf("%o", octa);
					break;
				case 'p':
					void *ptr = va_arg(ap, void *);
					printf("%p", ptr);
					break;
				case 'x':
					unsigned int hex = va_arg(ap, unsigned int);
					printf("%x", hex);
					break;
				case 'X':
					unsigned int hex2 = va_arg(ap, unsigned int);
					printf("%X", hex2);
					break;
				case '%':
					va_arg(ap, char *);
					printf("%%");
					break;

				default:
					putchar('%');
					putchar(format[i]);
					break;
			}
		} else
		{
			putchar(format[i]);
		}
	}
	return (size);
}
