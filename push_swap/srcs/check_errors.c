/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:37:47 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:45:31 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_size_of(char **str);
static int	check_repeat(char **str);
static int	check_if_is_number(char **str);

int	check_errors(char **str)
{
	if (check_repeat(str) == -1)
	{
		print_msg("Your input has repetitions", 1);
		return (-1);
	}
	if (check_if_is_number(str) == -1)
	{
		print_msg("Not a valid number", 1);
		return (-1);
	}
	if (check_size_of(str) == -1)
	{
		print_msg("The size of your number exceeds limits", 1);
		return (-1);
	}
	return (0);
}

static int	check_size_of(char **str)
{
	int			i;
	long long	checker;

	i = 1;
	while (str[i])
	{
		checker = ft_atoi(str[i]);
		if (!(checker > INT_MIN || checker < INT_MAX))
			return (-1);
		i++;
	}
	return (0);
}

static int	is_sign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	check_if_is_number(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (!(is_sign(str[i][j]) || ft_isdigit(str[i][j])))
			return (-1);
		j++;
		while (str[i][j] != '\0')
		{
			if (!(ft_isdigit(str[i][j])))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static int	check_repeat(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i] != 0)
	{
		j = i + 1;
		while (str[j] != 0)
		{
			if (ft_strncmp(str[i], str[j], ft_strlen(str[j]) \
				+ ft_strlen(str[j])) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
