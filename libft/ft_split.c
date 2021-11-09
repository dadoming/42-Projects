/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:41:12 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/09 16:41:04 by dadoming         ###   ########.fr       */
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

/*
static	char	**ft_do_the_split(char const *s, char c, int split_amount,
		char **split, int i, int j, int main_string_iterator)
{
	int	word_amount;

	while (i < split_amount)
	{
		word_amount = ft_amount_of_letters(s, c) + 1;
		split[i] = malloc(sizeof(char) * (word_amount + 1));
		if (!split[i])
			return (NULL);
		while (j < word_amount)
		{
			while (s[main_string_iterator] == c)
				main_string_iterator++;
			split[i][j++] = (char)s[main_string_iterator];
			main_string_iterator++;
			if (s[main_string_iterator] == c)
			{
				split[i][j] = '\0';
				j = 0;
				break ;
			}
		}
		i++;
	}
	split[i] = 0;
	return (split);
}
*/

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_amount;
	int		main_string_iterator;
	int		i;
	int		j;

	j = 0;
	i = 0;
	main_string_iterator = 0;
	split_amount = ft_amount_of_splits(s, c) + 1;
	split = malloc(sizeof(char *) * (split_amount + 1));
	if (!split || !s)
		return (0);
	ft_do_the_split(s, c, split_amount, split, i, j, main_string_iterator);
	free(split);
	return (split);
}

/*
char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		locator;
	char	**split;

	if (!s || !(split = malloc((ft_amount_of_splits(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	locator = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && locator < 0)
			locator = i;
		else if ((s[i] == c || i == ft_strlen(s)) && locator >= 0)
		{
			split[j++] = word_dup(s, locator, i);
			locator = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


int main(void)
{
    char *str = "       dbhsdk      ";
    char c = ' ';    
    char **strfinal;
    int i = 0;
    
    strfinal = ft_split(str, c);
    while (i <= (ft_amount_of_splits(str, c) + 1))
    {
        printf("%s\n", strfinal[i]);
        i++;
    }
}
*/
