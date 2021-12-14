#include "ft_printf.h"

/*	The character % is followed by one of the following 	characters:
*
* 	-> The flag character:
* 	-> The field width
* 	-> The precision
* 	-> The length modifier
*
*	É preciso fazer um counter de quantidades de 			% seguidos da letra que queremos
*
*	Para printar '%' é necessário escrever:
*		printf("%%");	otherwise nao funciona
*
*
*	Por exemplo add(3, 1, 2, 3) -> 6
*vablabla(primeiro argumento aka num argumentos, os argumentos a tratar pela funcao variadica)
*
* ## +INFO PRINTF LINKS ##  
*	Printf Manual: http://swoolley.org/man.cgi/3/printf
*
* ########################
*/

int check_numparameters(char *str) //is this even neccessary??
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while(str)
	{
		if (str[i] == '%')
		{
			if(str[i + 1] == '%')
				i++;
			else if (str[i + 1] == 'c')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 's')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'p')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'i')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'u')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'x')
			{
				counter++;
				i++;
			}
			else if (str[i + 1] == 'X')
			{
				counter++;
				i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	return(counter);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int i;

	i = 0;

	va_start(ap, str);

	va_arg()
	
	while (str[i])
	{
		if(str[i] == '%')
		{
			if(str[i + 1] == '%' && str[i + 2] == '%')
			{
				ft_putchar('%');
			}
			else if(str[i + 1] == 'c')
			{
				
				ft_putchar(str[i]);
				i++;
			}
			else if(str[i + 1] == 's')
			{
				ft_putstr(argumento variadico passado)
				i++;
			}
			else if(str[i + 1] == 'p')
			{
				ft_ptr_address(); -> //ft_itoa
				i++;
			}
			else if(str[i + 1] == 'd')
			{
				ft_itoa_and_print();
				i++;
			}
			else if(str[i + 1] == 'i')
			{
				//d or i??
			}
			else if(str[i + 1] == 'u')
			{
				ft_unsigned_integer()
				i++;
			}
			else if(str[i + 1] == 'x')
			{
				ft_unsigned_hexadecimal_integer();
			}
			else if(str[i + 1] == 'X')
			{
				ft_unsigned_hexadecimal_integer_CAPITAL_LETTERS();
			}

		}
		else 
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
}

int main(void) {
  char c = '6';
  char *str = "Happy String";
  int d = 420;

  
  printf("### %%c ###\n\nREAL: %c\n",c);
  ft_printf("MEU: %c\n", c);

  printf("### %%s ###\n\nREAL: %s\n", str);
  ft_printf("MEU: %s\n", str);

  printf("### %%p ###\n\nREAL: %p\n", &c);
  ft_printf("MEU: %p\n", &c);
  
  printf("### %%d ###\n\nREAL: %d\n", d);
  ft_printf("MEU: %d\n", d);

  printf("### %%i ###\n\nREAL: %i\n", d);
  ft_printf("MEU: %i\n", str);

  printf("### %%u ###\n\nREAL: %u\n", );
  ft_printf("MEU: %u\n", );

  printf("### %%x ###\n\nREAL: %x\n", );
  ft_printf("MEU: %x\n", );

  printf("### %%X ###\n\nREAL: %X\n", );
  ft_printf("MEU: %X\n", );
}