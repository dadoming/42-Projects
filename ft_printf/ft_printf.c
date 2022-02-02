#include "ft_printf.h"

int check_if_in_type (int c)
{
	if(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int conversion(char c, va_list arg_ptr)
{
	char_counter = 0;
	if (c == 'c')
		char_counter += ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		char_counter += ft_putstr(va_arg(arg_ptr, char *));
 	else if (c == 'd' || c == 'i')
		char_counter += ft_putnbr(va_arg(arg_ptr, int));
	 else if (c == 'p')
	{
		char_counter += write(1, "0x", 2);
	 	char_counter += ft_print_pointeraddress(va_arg(arg_ptr, unsigned long), "0123456789abcdef", 16);
	}
	else if (c == 'u')
		char_counter += ft_print_unsigned_and_hexa(va_arg(arg_ptr, unsigned int), "0123456789", 10);
	else if (c == 'x')
		char_counter += ft_print_unsigned_and_hexa(va_arg(arg_ptr, unsigned int), "0123456789abcdef", 16);	
	else if (c == 'X')
		char_counter += ft_print_unsigned_and_hexa(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF", 16);
	return (char_counter);
}

int ft_printf(char const *format, ...)
{
	va_list arg_ptr;
	int i;
	int counter;

	va_start (arg_ptr, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1] == '%')
		{	
			counter += ft_putchar('%');
			i += 2;
		}
		else if (format[i] == '%' && check_if_in_type (format[i + 1]))
		{
			counter += conversion (format[i + 1], arg_ptr);
			i += 2;
			//printf("/%d\\", counter);
		}
		else
		{
			counter += ft_putchar (format[i]);
			//printf("_%d_", counter);
			i++;
		}
	}
	va_end (arg_ptr);
	return (counter);
}

int main(void)
{
  char c = '9';
  char *str = "LEZZZ GOOO wuuu";
  int d = 420;
  int main_counter = 0;
/* funciona mas dá warning apenas pq n se deve meter null
  printf("\n### (null) ###\n");
  main_counter = printf("%s, ", NULL);
  printf("%d\n", main_counter);
  main_counter = ft_printf("%s, ", NULL);
  printf("%d", main_counter);
*/
  printf("\n\n### Sem %% ###\n");
  main_counter = printf("REAL: Bitchaz, ");
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  Bitchaz, ");
  ft_printf("%d", main_counter );

  printf("\n\n### %%%% ###\n");
  main_counter  = printf("REAL: %% %%%% %%%%%%, ");
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  %% %%%% %%%%%%, ");
  ft_printf("%d", main_counter );
  
  printf("\n\n### %%c ###\n");
  main_counter  = printf("REAL: %c, ",c);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %c, ", c);
  printf("%d", main_counter );

  printf("\n\n### %%d ###\n");
  main_counter  = printf("REAL: %d, ", d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %d, ", d);
  printf("%d", main_counter );

  printf("\n\n### %%i ###\n");
  main_counter  = printf("REAL: %i, ", d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %i, ", d);
  printf("%d", main_counter );

  printf("\n\n### %%s ###\n");
  main_counter  = printf("REAL: %s, ", str);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %s, ", str);
  printf("%d", main_counter );

  printf("\n\n### %%p ###\n");
  main_counter  = printf("REAL: %p, ", &d);
  printf("%d\n", main_counter );
  main_counter  = ft_printf("MEU:  %p, ", &d);
  printf("%d", main_counter );

  printf("\n\n### %%u ###\n");
  main_counter = printf("REAL: %u, ", d);
  printf("%d\n", main_counter );
  main_counter = ft_printf("MEU:  %u, ", d);
  printf("%d", main_counter );
  
  printf("\n\n### %%x ###\n");
  main_counter = printf("REAL: %x, ", d);
  printf("%d\n", main_counter);
  main_counter = ft_printf("MEU:  %x, ", d);
  printf("%d", main_counter);

  printf("\n\n### %%X ###\n");
  main_counter = printf("REAL: %X, ", d);
  printf("%d\n", main_counter);
  main_counter = ft_printf("MEU:  %X, ", d);
  printf("%d\n", main_counter);
}
