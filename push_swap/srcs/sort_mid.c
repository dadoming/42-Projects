/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:26:02 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 18:51:24 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	last_is_biggest(t_list **a, t_list **b)
{
	pa(a, b);
	ra(a);
}

static void	biggest_before_last(t_list **a, t_list **b)
{
	rra(a);
	pa(a, b);
	ra(a);
	ra(a);
}

static void	sort_smallest(t_list **a, t_list **b)
{
	pa(a, b);
	sa(a);
}

void	sort_four(t_list **a, t_list **b)
{
	pb(a, b);
	sort_three(a);
	if ((*a)->content > (*b)->content)
		pa(a, b);
	else if ((*b)->content > (*a)->next->next->content)
		last_is_biggest(a, b);
	else if ((*b)->content > (*a)->next->content)
	{
		biggest_before_last(a, b);
	}
	else if ((*b)->content > (*a)->content)
		sort_smallest(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	pb(a, b);
	sort_four(a, b);
	if ((*a)->content > (*b)->content)
		pa(a, b);
	else if ((*a)->next->next->next->content < (*b)->content)
		last_is_biggest(a, b);
	else if ((*a)->next->next->content < (*b)->content)
		biggest_before_last(a, b);
	else if ((*a)->next->content < (*b)->content)
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else if ((*a)->content < (*b)->content)
		sort_smallest(a, b);
}
