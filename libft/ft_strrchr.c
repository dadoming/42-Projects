/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:09:10 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:45:44 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen((char*)str);
	while (i > 0)
	{
		if (str[i] == (unsigned char )c)
			return ((char*)&str[i]);
		i--;
	}
	return(NULL); 
}
/*
int main(void)
{
	char str[] = "akfyd.aldfbl";
	char *aux = ft_strrchr(str, 'b');
	printf("%s", aux);
}
*/