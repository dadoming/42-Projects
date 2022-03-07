/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:48 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 16:45:54 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[counter])
	{
		ft_putchar(str[counter]);
		counter++;
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	int	a;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		g_char_counter += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else if (n < 10)
	{
		a = (n % 10) + '0';
		g_char_counter += ft_putchar(a);
	}
	return (g_char_counter);
}
