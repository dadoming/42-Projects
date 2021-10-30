/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:45:56 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:45:49 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    int len;
    char *trim;

    i = 0;
    while ((s1[i] != '\0') && ft_strchr(set, s1[i])) 
        i++;
    len = ft_strlen(s1); 
    while ((s1[len - 1] != 0) && ft_strchr(set, s1[len - 1])) 
        len--;
    trim = malloc(len - i + 1);
    if (trim == NULL)
        return (NULL);
    j = 0;
    while (i < len)
    {
        trim[j] = s1[i];
        j++;
        i++;
    }
    trim[j] = '\0';
    return (trim);
}
/*
int main(void)
{
    char *str = "eeeeesta string sera trimedee";
    char *e = "e";

    printf("%s", ft_strtrim(str, e));
}
*/