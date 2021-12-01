#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char *get_line(char *full_string)
{
	char *line;
	int i;

	i = 0;
	while(full_string[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while(full_string[i] != '\n' && full_string[i] != '\0')
	{
		line[i] = full_string[i];
		i++;
	}
	if(full_string[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *read_file(int fd, char *full_string)
{
	char *buff;
	int read_count;

	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
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
		printf("STEP >>%s<<\n\n", full_string);
	free(buff);
	return(full_string);
}

char *get_next_line(int fd)
{
	static char *full_string;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_string = read_file(fd, full_string);
	if (!full_string)
		return (0);
	printf("%s", full_string);
	line = get_line(full_string);
	return(line);
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