/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:43:49 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:51:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **head_of_stack)
{
	t_list	*top_node;
	t_list	*temp;

	top_node = NULL;
	if (*head_of_stack && ft_lstsize(*head_of_stack) > 1)
		top_node = *head_of_stack;
	temp = top_node;
	*head_of_stack = top_node -> next;
	while (temp->next)
		temp = temp->next;
	temp->next = top_node;
	top_node->next = NULL;
}

void	ra(t_list **stack_a)
{
	if (*stack_a)
	{
		rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_list **stack_b)
{
	if (*stack_b)
	{
		rotate(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
