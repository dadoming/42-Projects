#include "ft_printf.h"

/*	The character % is followed by one of the following characters:
*
* 	-> The flag character:
* 	-> The field width
* 	-> The precision
* 	-> The length modifier
*
*	É preciso fazer um counter de quantidades de % seguidos da letra que queremos
*
*
*
*	Por exemplo add(3, 1, 2, 3) -> 6
*	vablabla(primeiro argumento aka num argumentos, 
*	os argumentos a tratar pela funcao variadica)
*
* ## +INFO PRINTF LINKS ##  
*	Printf Manual: http://swoolley.org/man.cgi/3/printf
*
* ########################
*/

int	ft_printf(const char *str, ...)
{
	va_list arg_ptr;
	int i;

	int char_and_int_controller;
	char *string_controller;

	i = 0;

	va_start(arg_ptr, str);
	
	while (str[i])
	{
		if(str[i] == '%')
		{
            i++;
			if((str[i] == '%' && str[i + 1] != '%') || 
                (str[i] == '%' && str[i + 1] == '%' && str[i + 2] == '%'))
			{
				ft_putchar('%');
			}
			else if(str[i] == 'c')
			{
				char_and_int_controller = va_arg(arg_ptr,int);
				ft_putchar(char_and_int_controller);
                i++;
			}
            else if(str[i] == 'd')
			{
				char_and_int_controller = va_arg(arg_ptr,int);
				ft_putstr(ft_itoa(char_and_int_controller));
                i++;
			}
			else if(str[i] == 'i')
			{
				char_and_int_controller = va_arg(arg_ptr,int);
				ft_putstr(ft_itoa(char_and_int_controller));
                i++;
			}
			else if(str[i] == 's')
			{
				string_controller = va_arg(arg_ptr, char *);
				ft_putstr(string_controller);
				i++;
			}
			// else if(str[i + 1] == 'p')
			// {
			// 	ft_ptr_address(); -> //ft_itoa
			// 	i++;
			// }
			// else if(str[i + 1] == 'u')
			// {
			// 	ft_unsigned_integer()
			// 	i++;
			// }
			// else if(str[i + 1] == 'x')
			// {
			// 	ft_unsigned_hexadecimal_integer();
			// }
			// else if(str[i + 1] == 'X')
			// {
			// 	ft_unsigned_hexadecimal_integer_CAPITAL_LETTERS();
			// }

		}
		else 
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg_ptr);
	return (0);
}

int main(void) {
  char c = '6';
  char *str = "Happy String";
  int d = 420;

  printf("\n### %%%% ###\n\nREAL: %% %%%% %%%%%%\n");
  ft_printf(" MEU: %% %%%% %%%%%%");

  printf("\n\n### %%c ###\n\nREAL: %c\n",c);
  ft_printf("MEU: %c", c);
  
  printf("\n\n### %%d ###\n\nREAL: %d\n", d);
  ft_printf("MEU: %d", d);

  printf("\n\n### %%i ###\n\nREAL: %i\n", d);
  ft_printf("MEU: %i", d);

  printf("\n\n### %%s ###\n\nREAL: %s\n", str);
  ft_printf("MEU: %s", str);

//   printf("\n\n### %%p ###\n\nREAL: %p\n");
//   ft_printf("MEU: %p\n");
  

//   printf("\n\n### %%u ###\n\nREAL: %u\n");
//   ft_printf("MEU: %u\n");

//   printf("\n\n### %%x ###\n\nREAL: %x\n");
//   ft_printf("MEU: %x\n");

//   printf("\n\n### %%X ###\n\nREAL: %X\n");
//   ft_printf("MEU: %X\n");
}