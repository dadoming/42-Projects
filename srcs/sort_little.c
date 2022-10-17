/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:31:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 18:06:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_list **a)
{
	if ((*a)-> content > (*a)-> next -> content)
		sa(a);
}

void	sort_three(t_list **a)
{
	if (((*a)->next->next->content < (*a)->next->content \
			&& (*a)->next->content > (*a)->content))
	{
		if ((*a)->content > (*a)->next->next->content)
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else if ((*a)->content > (*a)->next->content \
		&& (*a)->next->content < (*a)->next->next->content)
	{
		if ((*a)->content > (*a)->next->next->content)
			ra(a);
		else
			sa(a);
	}
	else if ((*a)->content > (*a)->next->content && (*a)->content > (*a) \
	->next->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		sa(a);
		rra(a);
	}
}
