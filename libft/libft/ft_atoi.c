/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:31:08 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:13:34 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int neg;
    long int res;

    res = 0;
    neg = 1;
    i = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == 32)
        i++;
    if (str[i] == '+')
        i++;
    else if(str[i] == '-')
    {
        neg *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    if ((res * neg) < -2147483648 || (res * neg) > 2147483647)
        return (0);
    return(res * neg);
}