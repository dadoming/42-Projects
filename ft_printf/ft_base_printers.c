#include "ft_printf.h"

int	ft_print_unsigned_and_hexa(unsigned int nbr, char *base, int no)
{
	int				len;
	
	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr / len != 0)
	{
		ft_print_unsigned_and_hexa((nbr / len), base, no);
		char_counter += ft_putchar(base[nbr % len]);
	}
	else
		char_counter += ft_putchar(base[nbr % len]);
	return (char_counter);
}

int	ft_print_pointeraddress(unsigned long nbr, char *base, int no)
{
    int				len;
	
	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr / len != 0)
	{
		ft_print_pointeraddress((nbr / len), base, no);
		char_counter += ft_putchar(base[nbr % len]);
	}
	else
		char_counter += ft_putchar(base[nbr % len]);
	return (char_counter);
}