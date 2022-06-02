/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:26:02 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/02 15:26:44 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void *last_is_biggest(t_list **a, t_list **b)
{
	pa(a, b);
	ra(a);
	return(*a);
}

static void *biggest_before_last(t_list **a, t_list **b)
{
	rra(a);
	pa(a, b);
	ra(a);
	ra(a);
	return(*a);
}

static void *sort_smallest(t_list **a, t_list **b)
{
	pa(a, b);
	sa(a);
	return(*a);
}

t_list	*sort_four(t_list **a, t_list **b)
{
	pb(a, b);
	sort_three(a);
	if (FIRST > (*b)-> content)
		pa(a, b);
	else if ((*b)-> content > THIRD)
		last_is_biggest(a, b);
	else if ((*b)-> content > SECOND)
	{
		biggest_before_last(a, b);
	}
	else if ((*b)-> content > FIRST)
		sort_smallest(a, b);
	return (*a);
}

t_list *sort_five(t_list **a, t_list **b)
{
	pb(a, b);
	sort_four(a, b);
	if(FIRST > (*b)-> content)
		pa(a, b);
	else if(FORTH < (*b)-> content)
		last_is_biggest(a, b);
	else if(THIRD < (*b)-> content)
		biggest_before_last(a, b);
	else if(SECOND < (*b)-> content)
	{
		ra(a);
		pa(a, b);
		sa(a);
		rra(a);
	}
	else if(FIRST < (*b)-> content)
		sort_smallest(a, b);
	return(*a);
}
