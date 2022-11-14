/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:33 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:14:46 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

void	print_status(t_philo *p, char *status, char *color)
{
	long long	current_time;

	current_time = get_delta_t();
	sem_wait(table()->sem.print);
	printf("%s%lld\t%d\t%s%s\n", \
		color, current_time, p->index, status, RESET);
	sem_post(table()->sem.print);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	neg;
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

void	err_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*_append(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
