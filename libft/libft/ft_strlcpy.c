/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:34:52 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:24:03 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
  size_t i;

  i = 0;
  if (dstsize > 0)
  {
    while(src[i] != '\0')
    {
      if ( i == dstsize )
      {
        i--;
        break;
      }
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }
  while(src[i] != '\0')
  {
    i++;
  }
  return (i);
}
