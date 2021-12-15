/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:02:28 by dadoming          #+#    #+#             */
/*   Updated: 2021/12/15 14:49:44 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// /*https://stackoverflow.com/questions/48066271/how-to-print-a-pointer-address-without-printf/48066640
// https://www.tutorialspoint.com/computer_logical_organization/number_system_conversion.htm
// */

static int	ft_power(int x, int y)
{
	int	res;

	if (y < 0)
		return (0);
	else if (y == 0)
		return (1);
	else if (x == 0)
		return (0);
	else
	{
		res = x;
		while (y - 1)
		{
			res = res * x;
			y--;
		}
		return (res);
	}
}


int ft_hexa_converter(char *number)
{
    int i;
    int sum;
    int aux;
    int len;

    len = 0;
    while (number[i] != '\0')
    {
        len++;
        i++;
    }
    i = 0;
    while (--len >= 0)
    {
        aux = number[len];
        if (aux >= 48 && aux <= 57)
            aux = aux - 48;
        else if (aux >= 65 && aux <= 90)
            aux = aux - 55;
        else
            return 0;
        sum = sum + (aux * ft_power(16, i));
        i++;
    }
    return (sum);
}
