/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:51 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/09 05:24:54 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(int c)
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
					unsigned long), "0123456789abcdef");
	}
	else if (c == 'u')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789");
	else if (c == 'x')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789abcdef");
	else if (c == 'X')
		g_char_counter = ft_print_unsigned_and_hexa(va_arg(arg_ptr,
					unsigned int), "0123456789ABCDEF");
	return (g_char_counter);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg_ptr;

	g_counter = 0;
	va_start (arg_ptr, format);
	g_i = 0;
	while (format[g_i])
	{
		if (format[g_i] == '%' && !check(format[g_i + 1]) && format[g_i + 2])
			g_i += 2;
		if (format[g_i] == '%' && format[g_i + 1] == '%')
		{	
			g_counter += ft_putchar('%');
			g_i++;
		}
		else if (format[g_i] == '%' && check(format[g_i + 1]))
		{
			g_counter += conversion (format[g_i + 1], arg_ptr);
			g_i++;
		}
		else
			g_counter += ft_putchar (format[g_i]);
		g_i++;
	}
	va_end (arg_ptr);
	return (g_counter);
}
