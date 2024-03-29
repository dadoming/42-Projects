/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:15:06 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/29 17:15:06 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*free_empty(char **empty_string)
{
	if (empty_string)
		free(empty_string);
	return (NULL);
}

static void	free_splitted(char **s, int i)
{
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	bool_check(char *s)
{
	if ((s[0] == ('+' || '-')) && ft_isdigit(s[1]))
		return (1);
	return (0);
}

t_list	*init_stacks_string(char **splitted_argv, int start, int i)
{
	t_list	*head;
	t_list	*tmp;

	if (!splitted_argv[i] || \
		(bool_check(splitted_argv[0]) && splitted_argv[1] == 0))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (free_empty(splitted_argv));
	}
	if (check_errors(splitted_argv, start) == -1)
	{
		free_splitted(splitted_argv, 0);
		return (NULL);
	}
	head = ft_lstnew(ft_atoi(splitted_argv[i++]));
	tmp = head;
	while (splitted_argv[i] != 0)
	{
		tmp->next = ft_lstnew(ft_atoi(splitted_argv[i++]));
		tmp = tmp->next;
	}
	tmp -> next = NULL;
	free_splitted(splitted_argv, 0);
	return (head);
}

t_list	*init_stacks(int argc, char **argv)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	if (argc == 2)
		return (init_stacks_string(ft_split(argv[1], ' '), 0, 0));
	i = 1;
	if (check_errors(argv, 1) == -1)
		return (NULL);
	head = ft_lstnew(ft_atoi(argv[i++]));
	tmp = head;
	while (i < argc)
	{
		tmp->next = ft_lstnew(ft_atoi(argv[i]));
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (head);
}
