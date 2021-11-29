#include <stdio.h>

int ft_strlen(char *str)
{
   int i;

   i = 0;
   while(str[i] != '\0')
      i++;
   return(i);
}

char  *get_next_line(int fd)
{
   FILE *the_file = fopen("the_text_file.txt", "r");
   if(the_file == NULL)
      return(0);
   char *line[BUFFER_SIZE];
   static int i;

   i = 0;
   while(str[i] !='\0')
   {
      line[i] = str[i];
      if (str[i] != '\n')
      {
         i++;
         line[i] = '\n';
         return(line);
      }
      else if (str[i] != '\0')
      {
         i++;
         line[i] = '\0';
         return(line);
      }
      else
         i++;
   }
}


/*to read a text file line by line é preciso chamar o nome do ficheiro, 
e inserir o tipo de modo de leitura, neste programa irei o usar only read "r",
depois tem que se fazer um protect caso nao funcione. Tem que se declarar a 
variavel em que se vao colocar as linhas de texto e dar-lhe um size. fgets é 
o get next line

*/

int main()
{
  FILE *the_file = fopen("the_text_file.txt", "r");
  if(the_file == NULL)
  {
    perror("Unable to open the file");
    exit(1);
  }
  char line[100];
  while(fgets(line, sizeof(line), the_file))
  {
      printf("%s", line);;
  }
  return 0;
}

char *fgets(char *str, int n, FILE *stream);
/*
The C library function char *fgets(char *str, int n, FILE *stream) reads a 
line from the specified stream and stores it into the string pointed to by str.
It stops when either (n-1) characters are read, the newline 
character is read, or the end-of-file is reached, whichever comes first.

Parameters:
--> str − This is the pointer to an array of chars where the string read is stored.

--> n − This is the maximum number of characters to be read (including the final null-character). 
            Usually, the length of the array passed as str is used.

--> stream − This is the pointer to a FILE object that identifies the stream where characters are read from.

Return Value
On success, the function returns the same str parameter. 
If the End-of-File is encountered and no characters have been read, 
the contents of str remain unchanged and a null pointer is returned.

If an error occurs, a null pointer is returned.


########## EXAMPLE ############

#include <stdio.h>

int main () {
   FILE *fp;
   char str[60];

   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      puts(str);
   }
   fclose(fp);
   
   return(0);
}


######## READ FUNCTION #########
https://stackoverflow.com/questions/19769542/reading-from-file-using-read-function



https://pubs.opengroup.org/onlinepubs/000095399/functions/read.html















*/
andre get next line:

#include "get_next_line.h"
########################
char	*find_last_index(char *str)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char));
	if (res == NULL || str == NULL || ft_strlen(str) == 0)
		return (NULL);
	res[0] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		res = str_appendc(res, str[i]);
		if (str[i] == '\n' || str == NULL)
			break ;
		i++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		k;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		new[i] = s1[i];
	k = -1;
	while (s2[++k] != '\0')
		new[i + k] = s2[k];
	new[i + k] = '\0';
	return (new);
}

void	init_staticstr(char *str)
{
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
}
#########################
char	*get_next_line(int fd)
{
	static char	*str;
	char		temp[BUFFER_SIZE + 1];
	char		*res;
	int			r_count;

	r_count = BUFFER_SIZE;
	init_staticstr(str);
	if (str == NULL)
		str = (char *)malloc(sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0 || str == NULL)
		return (NULL);
	while (!ft_strchr(str, '\n') && r_count == BUFFER_SIZE)
	{
		r_count = read(fd, &temp, BUFFER_SIZE);
		if (r_count == -1)
			return (NULL);
		else if (r_count == 0)
			break ;
		temp[r_count] = '\0';
		str = ft_strjoin(str, temp);
	}
	res = find_last_index(str);
	str += ft_strlen(res);
	return (res);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}
##################
char	*str_appendc(char *str, char c)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (temp == NULL)
		return (NULL);
	i = 0;
	if (str != 0)
	{
		while (str[i] != '\0')
		{
			temp[i] = str[i];
			i++;
		}
		free(str);
	}
	temp[i++] = c;
	temp[i] = '\0';
	return (temp);
}

t_read	*new_read(void)
{
	t_read	*new;

	new = (t_read *)malloc(sizeof(t_read));
	if (new == NULL)
		return (NULL);
	new->r_total = 0;
	new->r_count = 0;
	new->temp = '\0';
	return (new);
}


















get next line by ruben

#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}