/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:35:23 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:49:11 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_list **head_of_stack)
{
	t_list	*temp;
	t_list	*bot;

	if (ft_lstsize(*head_of_stack) > 1)
	{
		temp = *head_of_stack;
		bot = ft_lstlast(*head_of_stack);
		while (temp -> next -> next)
			temp = temp -> next;
		temp -> next = NULL;
		bot -> next = *head_of_stack;
		*head_of_stack = bot;
	}
}

void	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		rev_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		rev_rotate(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
