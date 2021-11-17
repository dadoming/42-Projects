/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:47:33 by dadoming          #+#    #+#             */
/*   Updated: 2021/11/17 16:01:55 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"

#include <fcntl.h> //open
#include <stdio.h>
#include <unistd.h> //read
#include <string.h> //strchr
#include <stdlib.h> //malloc
//#ifndef BUFFER_SIZE
//# define BUFFER_SIZE 256

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	j = 0;
	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	get_next_line(int fd)
{
	static char	*line;
	char		buf[256];
	int			i;
	int			nbytes;

	nbytes = sizeof(buf);
	if (!(line = malloc(sizeof(char))))
		return (0);
	while (!(strchr(line, '\n')))
	{
		line = ft_strjoin(line, buf);
	}
	return (line);
}

/*E SE?
	

*/











int main(int argc, char **argv)
{
	int 	file;
	char	*line;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
		{
			printf("ERRO");
		}
		line = get_next_line(file);
		while (line != NULL)
		{
			printf("%s", line);
			printf("\n");
			line = get_next_line(file);
		}
	}
	else
		printf("error, argc != 2");
}
