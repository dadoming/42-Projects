/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:44:47 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/09 17:17:32 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static	int	ft_amount_of_splits(char const *s, char c)
{
	int	split_amount;
	int	i;

	split_amount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			split_amount++;
		while (s[i] == c && s[i + 1] == c)
			i++;
		i++;
	}
	return (split_amount);
}

char	**ft_split(char const *s, char c)
{
	int		end;
	int		i;
	int		number_of_splits;
	char	**split;

	end = 0;
	i = 0;
	number_of_splits = ft_amount_of_splits(s, c) + 1;
	split = malloc(number_of_splits);
	if (!split)
		return (0);
	split[number_of_splits - 1] = '\0';
	while (split[i] != '\0')
	{
		while (*s == c)
			s++;
		while (*s != c)
		{
			split[i] = *s;
			end++;
			s++;
		}
		split[i] = malloc(ft_strlen(s - end + 1));
		if (!split[i])
			return (0);
	}
}

int	main(void)
{
	char	*str;
	char	c;
	char	**strfinal;
	int		i;

	*str = "ola tudo bem";
	c = ' ';
	i = 0;
	strfinal = ft_split(str, c);
	while (i <= (ft_amount_of_splits(str, c) + 1))
	{
		printf("%s\n", strfinal[i]);
		i++;
	}
}