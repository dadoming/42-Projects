/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:34:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:53:30 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **head_of_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *head_of_stack;
	second = (*head_of_stack)->next;
	third = second->next;
	*head_of_stack = second;
	second->next = first;
	first->next = third;
}

void	sa(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 1)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) > 1)
	{
		swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 1)
		swap(stack_a);
	if (ft_lstsize(*stack_b) > 1)
		swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
