/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:55:47 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:43:49 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *str)
{
    char *dup;
    int i;

    i = 0;
    dup = ft_malloc((1 + ft_strlen(str)) * sizeof(char));
    if (dup == NULL)
        return (NULL);
    while(str[i] != '\0')
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}  
/*
int main(void)
{
    char s[] = "lololololo";
    printf("%s", ft_strdup(s));
}
*/