/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:34:52 by dadoming          #+#    #+#             */
/*   Updated: 2021/10/29 03:44:57 by dadoming         ###   ########.fr       */
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
/*
void test(int n)
{
  char *src = "-A string estupida";
  char dst[19];
  int a;

  a = ft_strlcpy(dst, src, n);
  printf("Inicial: %s\n",src);
  printf("Final: %s\n",dst);
  printf("Lenght: %d\n\n", a);
}

int main()
{
  test(19);
  test(18); // y da fuck is
  test(17); // test(17) com menos duas do
  test(10); // que test(18)
  test(2);
  test(1);
  test(0);
}*/
