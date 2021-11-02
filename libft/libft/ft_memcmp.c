/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:36:27 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:20:47 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    unsigned char *auxstr1 = (unsigned char*)str1;
    unsigned char *auxstr2 = (unsigned char*)str2;
    int i;
    
    i = 0;
    while(((auxstr1[i] || auxstr2[i]) != '\0') && n > 0)
    {
        i++;
        n--;
    }
    return (auxstr1[i] - auxstr2[i]);
}
