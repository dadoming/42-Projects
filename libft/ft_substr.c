/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:18:49 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:46:11 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *str, unsigned int start, size_t len)
{
    char *sub; 
    size_t sublen;
    int i;

    i = 0;
    sublen = ft_strlen(str);
    if (start > sublen)
        return (NULL);
    start -= 1;
    sublen -= start - len - 1; 
    sub = malloc(sublen * sizeof(char));
    if(sub == NULL)
        return (NULL);
    start += 1;
    while(len > 0)
    {
        sub[i] = str[start];
        start++;
        i++;
        len--;
    }
    sub[i] = '\0';
    return (sub);
}
/*
int main(void)
{
    char *str = "lavaiela";
    printf("%s", ft_substr(str, 1, 2));
}
*/