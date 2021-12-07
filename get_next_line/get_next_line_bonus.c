/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:17:05 by dadoming          #+#    #+#             */
/*   Updated: 2021/12/07 20:37:24 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *full_string)
{
	char	*buff;
	int		read_count;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_count = 1;
	while (!ft_strchr(full_string, '\n') && (read_count != 0))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free (buff);
			return (0);
		}
		buff[read_count] = '\0';
		full_string = ft_strjoin(full_string, buff);
	}
	//printf("STEP >>%s<<\n\n", full_string);
	free(buff);
	return (full_string);
}

char *get_line(char *full_string)
{
	char	*line;
	int		i;

	i = 0;
	if (!full_string[i])
		return (0);
	while (full_string[i] != '\n' && full_string[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (full_string[i] != '\n' && full_string[i] != '\0')
	{
		line[i] = full_string[i];
		i++;
	}
	if (full_string[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extra_read(char *full_string)
{
	int		i;
	int		j;
	char	*extra;

	i = 0;
	while (full_string[i] != '\0' && full_string[i] != '\n')
		i++;
	if (!full_string[i])
	{
		free(full_string);
		return (0);
	}
	extra = malloc(sizeof(char) * (ft_strlen(full_string) - i + 1));
	if (!extra)
		return (0);
	j = 0;
	i++;
	while (full_string[i] != '\0')
	{
		extra[j++] = full_string[i++];
	}
	extra[j] = '\0';
	free(full_string);
	return (extra);
}

char	*get_next_line(int fd)
{
	static char		*full_string;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_string = read_file(fd, full_string);
	if (!full_string)
		return (0);
	line = get_line(full_string);
	full_string = extra_read(full_string);
	return (line);
}
