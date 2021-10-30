/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:38:07 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:42:19 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *auxdst = (unsigned char*)dst;
	unsigned char *auxsrc = (unsigned char*)src;

	if(!dst && !src)
		return (0);
	while(n > 0)
	{
		*auxdst = *auxsrc;
		auxdst++;
		auxsrc++;
		n--;
	}
	return (dst);
}
/*
int main(void)
{
	char src[] = "bora la";
			//	  [-]
			//		[-]
	ft_memcpy(src, src + 2, 3);
	printf("%s", src);
}
*/