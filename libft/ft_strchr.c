/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:30:09 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/07 13:57:53 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while(s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return(NULL);
		i++;
	}
	return((char *)&s[i]);
}