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
	int j;
	int size;
	char word;
	char *string;
	int number;
	int octal;
	unsigned num;
	unsigned int octa;
	void *ptr;
	unsigned int hex;
	unsigned int hex2;
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
					word = va_arg(ap, int);
					printf("%c", word);
					break;
				case 's':
					string = va_arg(ap, char *);
					printf("%s", string);
					break;
				case 'd':
					number = va_arg(ap, int);
					printf("%d", number);
					break;
				case 'i':
					octal = va_arg(ap, int);
					printf("%i", octal);
					break;
				case 'u':
					num = va_arg(ap, unsigned);
					printf("%u", num);
					break;
				case 'o':
					octa = va_arg(ap, unsigned int);
					printf("%o", octa);
					break;
				case 'p':
					ptr = va_arg(ap, void *);
					printf("%p", ptr);
					break;
				case 'x':
					hex = va_arg(ap, unsigned int);
					printf("%x", hex);
					break;
				case 'X':
					hex2 = va_arg(ap, unsigned int);
					printf("%X", hex2);
					break;
				case '%':
					va_arg(ap, char *);
					printf("%%");
					break;

				default:
					putchar('%');
					putchar(format[j]);
					break;
			}
		} else
		{
			putchar(format[j]);
		}
	}
	return (size);
}
