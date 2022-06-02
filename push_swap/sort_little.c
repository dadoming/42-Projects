/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:31:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/02 15:27:09 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_two(t_list **a)
{
	if ((*a)-> content > (*a)-> next -> content)
		sa(a);
	return (*a);
}

t_list	*sort_three(t_list **a)
{
	if ((THIRD < SECOND && SECOND > FIRST))
	{
		if (FIRST > THIRD)
			rra(a);
		else if (FIRST < THIRD)
		{
			rra(a);
			sa(a);
		}
	}
	else if (FIRST > SECOND && SECOND < THIRD)
	{
		if(FIRST > THIRD)
			ra(a);
		else if(FIRST < THIRD)
			sa(a);
	}
	else if(FIRST > SECOND && FIRST > THIRD && SECOND > THIRD)
	{
		sa(a);
		rra(a);
	}
	return (*a);
}
