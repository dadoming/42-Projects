/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:47:18 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:40:29 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	else
		return (0);
}
/*
int main()
{
	int i = 0;
	char s[] = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[";
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) != 0)
			printf("%c", s[i]);
		if (ft_isalpha(s[i]) == 0)
			printf("!");
		i++;
	}
}*/
