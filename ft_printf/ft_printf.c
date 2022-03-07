/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:51 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 17:30:54 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_if_in_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	conversion(char c, va_list arg_ptr)
{
	g_char_counter = 0;
	if (c == 'c')
		g_char_counter = ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		g_char_counter = ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		g_char_counter = ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'p')
	{
		g_char_counter = write(1, "0x", 2);
		g_char_counter = ft_print_pointeraddress(va_arg(arg_ptr,
					unsigned long), "0123456789abcdef", 16);
	}
	else if (c == 'u')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789", 10);
	else if (c == 'x')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789ABCDEF", 16);
	return (g_char_counter);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		counter;
	va_list	arg_ptr;

	va_start (arg_ptr, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{	
			counter += ft_putchar('%');
			i++;
		}
		else if (format[i] == '%' && check_if_in_type (format[i + 1]))
		{
			counter += conversion (format[i + 1], arg_ptr);
			i++;
		}
		else
			counter += ft_putchar (format[i]);
		i++;
	}
	va_end (arg_ptr);
	return (counter);
}
