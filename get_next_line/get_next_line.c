/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:47:33 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/25 17:38:42 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> //read
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
/*
char	get_next_line(int fd)
{
	static char		*str;
	int 			BUFFER_SIZE = 256;
	char			buf[BUFFER_SIZE];
	char			*ret;
	int				read_n;
	

	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	while (!(strchr(str, '\n')))
	{
		read_n = read(fd, &buf, BUFFER_SIZE); //why '&buf'? : 			TO READ BYTE BY BYTE !!
		if(read_n == -1)// 	-> 	read nao leu nada, retornou -1
			return (0);
		else if(read_n == 0) // ->	if finished reading == '\0'
			break;
		buf[read_n] = '\0'; // if \n
		str = ft_strjoin(str, buf); //copia do que foi read para ----> static str !!
	}
	ret = ft_output(str);
	str += ft_strlen(ret); //str vai avancar um numero igual de caracteres == ao que foi lido nesta function call
	return (ret);
}
*/

int numbyte_to_read(char *str)
{
	int i = 0;
	
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];
	int bytes_read;
	static int i;
	char *str;
	
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	
	while (strchr(str, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		
		buf[bytes_read] = '\0';
		i++;
	}
	return (buf);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("ERRO");
			exit(0);
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("%s", line);
			printf("\n");
			line = get_next_line(fd);
		}
	}
	else
	{
		printf("error, argc != 2");
		exit(0);
	}
}

#endif