/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:35 by dadoming          #+#    #+#             */
/*   Updated: 2022/11/14 16:35:06 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_bonus.h"

static int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (len = 1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_filler(int aux, int len, char *str)
{
	if (aux == 0)
		str[len - 1] = '0';
	if (aux < 0)
	{
		str[0] = '-';
		aux *= -1;
	}
	while (--len >= 0 && aux != 0)
	{
		str[len] = (aux % 10) + 48;
		aux = aux / 10;
	}
	return (str);
}

char	*_itoa(int n)
{
	char	*str;
	int		len;
	long	aux;

	aux = n;
	len = ft_length(aux);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (ft_filler(aux, len, str));
}

sem_t	*open_sem(char *name, int sem_value)
{
	sem_t	*s;

	sem_unlink(name);
	s = sem_open(name, O_CREAT | O_EXCL, 0644, sem_value);
	return (s);
}
