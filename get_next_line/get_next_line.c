/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:47:33 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/29 21:09:42 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *find_line(char *str)
{
	char *output;
	int i;

	i = 0;
	output = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i] != '\0')
	{
		output[i] = str[i];
		if (str[i] == '\n')
		{
			output[i] = str[i];
			i++;
			output[i] = '\0';
			break ;
		}
		else if (str[i] == '\0')
		{
			output[i] = '\0';
			break ;
		}
		i++;
		printf("2");
	}
	free(str);
	return(output);
}

char *get_next_line(int fd)
{
	char *buf;
	int buff_read;
	static char *str;
	char *output;
	
	buf = malloc(BUFFER_SIZE + 1);
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	while (!ft_strchr(str, '\n') && buff_read == BUFFER_SIZE)
	{
	 	buff_read = read(fd, buf, BUFFER_SIZE);
		if (buff_read == -1)
			return (0);
		buf[buff_read] = '\0';
		str = ft_strjoin(str, buf);
		printf("1");
	}
	free(buf);
	output = find_line(str);
	str += ft_strlen(output);
	return (output);
}
*/

char *read_save(char *saved, int fd)
{
	char	*buff;
	int		read_count;

	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_count = 1;
	while (!(ft_strchr (saved, '\n')) && (read_count != 0))
	{
		read_count = read (fd, buff, BUFFER_SIZE);
		if(read_count == -1)
		{
			free (buff);
			return (0);
		}
		buff[read_count] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free (buff);
	return (saved);
}

char *get_output(char *saved)
{
	int i;
	char *output;

	i = 0;
	if (!saved[i])
		return (0);
	while (saved[i] && saved[i] != '\n')
		i++;
	output = malloc(sizeof(char) * (i + 2));
	if (!output)
		return (0);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		output[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		output[i] = saved[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char *save_extra(char *saved)
{
	char *stored;
	int stored_counter;
	int i;
	
	i = 0;
	while(saved[i] != '\n' && saved[i] != '\0')
		i++;
	if(!saved[i])
	{
		free(saved);
		return(0);
	}
	stored = malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if(!stored)
		return (0);
	i++;
	stored_counter = 0;
	while(saved[stored_counter])
	{
		stored[stored_counter] = saved[i];
		stored_counter++;
		i++;
	}
	stored[stored_counter] = '\0';
	free(saved);
	return (stored);
}

char	*get_next_line(int fd)
{
	static char 	*saved;
	char 			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_save(saved, fd);
	if (!saved)
		return (0);
	line = get_output(saved);
	saved = save_extra(saved);
	return (line);
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