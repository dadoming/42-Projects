/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:43:57 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 16:57:35 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//LIBRARIES
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

//FUNCTIONS
char		*get_next_line(int fd);
char		*read_file(int fd, char *full_string);
char		*get_line(char *full_string);
char		*extra_read(char *full_string);
char		*ft_strjoin(char *full_string, char *buff);
char		*ft_strchr(char *s, int c);
size_t		ft_strlen(char *str);

#endif