#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}


char *get_next_line(int fd)
{
    int print;
    char buf[256];
    static char *str;

    while(!(ft_strchr(str, '\n')))
    {
        print = read(fd, &buf, sizeof(buf));
        printf("%d\n", print);
        if(print == -1)
            return (0);
        if(print == 0)
            break;
        buf[print] = '\0';
        str = ft_strjoin(str, buf);
    }
    return(str);
}

int main(int argc, char **argv)
{
    int print;
    int fd;
    char *buf;
    char *c;


    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        buf = get_next_line(fd);
        printf("%s\n", buf);
    }
    else
        printf("erro");
}