/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:34:24 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/02 15:52:17 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *pop;
    
    if (*stack_b == NULL)
		    return ;
    if(ft_lstsize(*stack_b) > 0)
    {
        pop = *stack_b;
        *stack_b = pop -> next;
        pop->next = NULL;
        ft_lstadd_front(stack_a, pop);
        write(1, "pa\n", 3);
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *pop;

    if (*stack_a == NULL)
		return ;
    if(ft_lstsize(*stack_a) > 0)
    {
        pop = *stack_a;
        *stack_a = pop -> next;
        pop -> next = NULL;
        ft_lstadd_front(stack_b, pop);
        write(1, "pb\n", 3);
    }
}







