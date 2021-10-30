/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:15:26 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:44:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void f(unsigned int i, char *letter)
{
  printf("%d = %c ", i, letter[i]);
}
*/
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
  unsigned int i;

  if (!s || !f)
    return;
  i = 0;
  while (s[i] != '\0')
  {
    f(i, &s[i]);
    i++;
  }
}
/*
int main(void)
{
  char c[] = " ";
  ft_striteri(c, f);
}*/