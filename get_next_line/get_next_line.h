/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:43:57 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/29 21:24:26 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//FUNCTIONS

char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strchr(const char *s, int c);
char	*ft_strchr(char *s, int c);
size_t  ft_strlen(char *str);
char    *get_next_line(int fd);
char    *save_extra(char *saved);
char    *get_output(char *saved);
char    *read_save(char *saved, int fd);

#endif