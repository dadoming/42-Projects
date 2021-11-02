/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:58:16 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/02 17:22:50 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
  size_t srclen;
  size_t dstlen;
  size_t auxdst;
  size_t i;

  dstlen = ft_strlen(dst);
  srclen = ft_strlen(src);

  auxdst = dstlen;
  i  = 0;
  while(dst[i] != '\0')
  {
    dst[auxdst] = src[i];
    i++;
    auxdst++;
    if(auxdst == dstsize - dstlen)
      break;
  }
  dst[auxdst] = '\0';
  return(dstlen + srclen);
}
