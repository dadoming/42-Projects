/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:41:12 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/10 14:48:38 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_amount_of_splits(char const *s, char c)
{
	size_t	split_amount;
	size_t	i;

	split_amount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			split_amount++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (split_amount);
}

char	**ft_split(char const *s, char c)
{
	size_t			end;
	size_t			i;
	char			**split;
	const char		*start;

	i = 0;
	split = ft_calloc((ft_amount_of_splits(s, c) + 1), sizeof(*split));
	if (!split)
		return (0);
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		end = 0;
		while (*s && *s != c)
		{
			end++;
			s++;
		}
		if (*(s - 1) != c)
			split[i++] = ft_substr(start, 0, end);
	}
	return (split);
}
