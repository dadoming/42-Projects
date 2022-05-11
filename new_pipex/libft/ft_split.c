/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:41:12 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/11 16:11:26 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
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
*/

static size_t	words_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			j++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		j++;
	return (j);
}

static char	*word(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_arr(char **arr, char *s)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(s);
	return (NULL);
}

static char	**worker(char **arr, char *s1, char c, size_t j)
{
	size_t	i;
	char	*str;

	str = s1;
	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			arr[i] = word(s1, c);
			if (!arr[i])
				return (free_arr(arr, s1));
			s1 = s1 + ft_strlen(arr[i]);
			i++;
		}
		s1++;
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	char	*s1;
	size_t	j;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	j = words_count(s1, c);
	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!w_arr)
		return (NULL);
	return (worker(w_arr, s1, c, j));
}