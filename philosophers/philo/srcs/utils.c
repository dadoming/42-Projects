#include "../header/philo.h"

int ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
	{
		if (!*s1 && !*s2)
		{
			return (0);
		}
	}
	return (*--s1 - *--s2);
}

long	ft_atoi(const char *str)
{
	int			i;
	long 	neg;
	long	res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if (((res * neg) < INT_MIN) || ((res * neg) > INT_MAX))
			return (-1);
	}
	return ((int)res * neg);
}

void err_msg(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}
