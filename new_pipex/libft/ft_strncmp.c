/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:00:53 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/09 15:32:03 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*auxstr1;
	unsigned char	*auxstr2;

	auxstr1 = (unsigned char *)s1;
	auxstr2 = (unsigned char *)s2;
	while (n)
	{
		if (*auxstr1 != *auxstr2)
			return (*auxstr1 - *auxstr2);
		if (!(*auxstr1) || !(*auxstr2))
			return (0);
		auxstr1++;
		auxstr2++;
		n--;
	}
	return (0);
}
