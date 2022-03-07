/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_printers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:45 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 16:46:19 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_and_hexa(unsigned int arg_num,
	char *base_string, int base_number)
{
	int				len;

	len = 0;
	while (base_string[len])
		len++;
	if (arg_num / len != 0)
	{
		ft_print_unsigned_and_hexa((arg_num / len), base_string, base_number);
		g_char_counter += ft_putchar(base_string[arg_num % len]);
	}
	else
		g_char_counter += ft_putchar(base_string[arg_num % len]);
	return (g_char_counter);
}

int	ft_print_pointeraddress(unsigned long arg_num,
	char *base_string, int base_number)
{
	int				len;

	len = 0;
	while (base_string[len])
		len++;
	if (arg_num / len != 0)
	{
		ft_print_pointeraddress((arg_num / len), base_string, base_number);
		g_char_counter += ft_putchar(base_string[arg_num % len]);
	}
	else
		g_char_counter += ft_putchar(base_string[arg_num % len]);
	return (g_char_counter);
}
