/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:30:09 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:22:03 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
		{
			return((char*)&str[i]);
		}
		i++;
	}
	return(NULL);
}