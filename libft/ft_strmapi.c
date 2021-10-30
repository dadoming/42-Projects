/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:07:07 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:45:20 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char f(unsigned int i, char c)
{
  char j;
  j = i + c;
  return (j);
}
*/
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  int i;
  int length;
  char *str;

  i = 0;
  if((s[i] || f) == '\0' )
    return(0);
  length = ft_strlen(s);
  if(!(str = malloc(sizeof(char *) * (length + 1))))
    return (0);
  while(i < length)
  {
    str[i] = (*f)(i, s[i]);
    i++;
  }
  str[i] = '\0';
  return(str);
}