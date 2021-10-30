/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:19:20 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:41:57 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
    size_t i;
    const char *auxstr = (const char*)str;
    
    i = 0;
    while(n > 0)
    {
        if (auxstr[i] == c)
            return ((char*)&str[i]);
        i++;
        n--;
    }
    return (NULL);
}
/*
int main(void)
{
    char str[] = "abcde";
    int c = 'c';

    printf("%s",ft_memchr(str, c, 4));
}
*/