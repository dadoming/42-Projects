/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:34:24 by dadoming          #+#    #+#             */
/*   Updated: 2022/09/27 17:47:58 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*pop;

	if (*stack_b == NULL)
		return ;
	if (ft_lstsize(*stack_b) > 0)
	{
		pop = *stack_b;
		*stack_b = pop -> next;
		pop->next = NULL;
		ft_lstadd_front(stack_a, pop);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*pop;

	if (*stack_a == NULL)
		return ;
	if (ft_lstsize(*stack_a) > 0)
	{
		pop = *stack_a;
		*stack_a = pop -> next;
		pop -> next = NULL;
		ft_lstadd_front(stack_b, pop);
		ft_putstr_fd("pb\n", 1);
	}
}
