/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:18:49 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/04 21:29:08 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *str, unsigned int start, size_t len)
{
    char *sub; 
    int i;
    
    i = 0;
    if(start >= ft_strlen(str))
    {
        if(!(sub = malloc(ft_strlen(str) + 1)))
            return(NULL);
        sub[i] = '\0';
        return(NULL);
    }
    if (str == NULL)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}