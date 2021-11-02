/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:39:15 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:22:41 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    int s1len; 
    int s2len;
    int i; 
    int j;
    char *str;

    j = 0;
    i = -1;
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    str = malloc(s1len + s2len + 1);
    if (str == NULL)
        return (NULL);
    while (s1[++i] != '\0')
        str[i] = s1[i];
    while(s2[j] != '\0')
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}