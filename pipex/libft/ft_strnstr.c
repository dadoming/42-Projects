/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:16:54 by dadoming          #+#    #+#             */
/*   Updated: 2021/12/01 18:42:48 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && ((i + j) < len))
		{
			if (j == n - 1)
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *needle = "123";
	char *haystack = "abc123aaa";

	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s", strnstr(haystack, needle, -1));
}
