/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:48:59 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:40:37 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int main()
{
	int i;
	char s[] = "123675ctg";
	i = 0;
	while (s[i] != '\0')
	{
		ft_isdigit(s[i]);
		if (ft_isdigit(s[i]) != 0)
			printf("%c", s[i]);
		if(ft_isdigit(s[i]) == 0)
			printf("!");
		i++;
	}
}
*/