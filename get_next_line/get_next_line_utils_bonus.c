/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:17:03 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 17:09:33 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *full_string, char *buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!full_string)
	{
		full_string = malloc(sizeof(char));
		full_string[0] = '\0';
	}
	if (!full_string || !buff)
		return (0);
	j = 0;
	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(full_string) + ft_strlen(buff) + 1));
	if (!str)
		return (0);
	while (full_string[++i] != '\0')
		str[i] = full_string[i];
	while (buff[j] != '\0')
	{
		str[i++] = buff[j++];
	}
	str[i] = '\0';
	free (full_string);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
