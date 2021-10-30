/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:00:53 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:45:29 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;
    i = 0;
    while((str1[i] || str2[i]) != '\0' && i < n)
        i++;
    return(str1[i] - str2[i]);
}
/*
int main(void)
{
    char *str1 = "abcd";
    char *str2 = "bcde";

    printf("%d", ft_strncmp(str1, str2, 2));
}
*/