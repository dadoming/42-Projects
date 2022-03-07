/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:17:05 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/07 19:04:56 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *text)
{
	char	*buff;
	int		read_count;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_count = 1;
	while (!ft_strchr(text, '\n') && (read_count != 0))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free (buff);
			return (0);
		}
		buff[read_count] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (0);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extra_read(char *text)
{
	int		i;
	int		j;
	char	*extra;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (0);
	}
	extra = malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!extra)
		return (0);
	j = 0;
	i++;
	while (text[i] != '\0')
	{
		extra[j++] = text[i++];
	}
	extra[j] = '\0';
	free(text);
	return (extra);
}

char	*get_next_line(int fd)
{
	static char		*text[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text[fd] = read_file(fd, text[fd]);
	if (!text[fd])
		return (0);
	line = get_line(text[fd]);
	text[fd] = extra_read(text[fd]);
	return (line);
}
