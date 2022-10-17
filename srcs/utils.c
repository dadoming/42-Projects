/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:38:18 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/29 17:14:36 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_is_ordered(t_list *a)
{
	while (1)
	{
		if (a->next == NULL)
		{
			return (1);
		}
		if (a->content < a->next->content)
			a = a -> next;
		else
			break ;
	}
	return (0);
}

void	free_list(t_list **a)
{
	t_list	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a)-> next;
		free(*a);
		*a = temp;
	}
	a = NULL;
}
