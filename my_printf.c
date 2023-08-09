#include "shell.h"

/**
 * my_puts - puts string
 * @str: string
 */
void my_puts(const char *str)
{
	while (*str != '\0')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
/**
 * my_printf - cumstom printf
 * @format: foramt to be printed
 */
void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					my_puts(va_arg(args, const char *));
					break;
				default:
					write(STDOUT_FILENO, format, 1);
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
		}
		format++;
	}
	va_end(args);
}
