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
	char word;
	char *string;
	int number, octal, size, j;
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
