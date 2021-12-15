#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* >>> LIBRARIES <<< */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

/* >>> FUNCTIONS FOR OPERATORS <<< */
int	ft_printf(const char *str, ...);
void ft_putchar(char c); 	//%c
void ft_putstr(char *str);	//%s
void ft_ptr_address();
char *ft_itoa(int n);

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);


#endif