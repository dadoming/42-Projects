/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:18:49 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/09 16:18:24 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[i] = '\0';
		return (sub);
	}
	if (ft_strlen(str) < len)
		return (ft_strdup(&str[i]));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (len--)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
