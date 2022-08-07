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
    int new_head_value;
    
    if(ft_lstsize(*stack_b) > 0)
    {
        pop = *stack_b;
        *stack_b = (*stack_b) -> next;
        new_head_value = pop -> content;
        //ft_lstdelone(pop, NULL);
        ft_lstadd_front(stack_a, ft_lstnew(new_head_value));
        write(1, "pa\n", 3);
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *pop;
    int new_head_value;
    
    if(ft_lstsize(*stack_a) > 0)
    {
        pop = *stack_a;
        *stack_a = (*stack_a) -> next;
        new_head_value = pop -> content;
        //ft_lstdelone(pop, NULL);
        ft_lstadd_front(stack_b, ft_lstnew(new_head_value));
        write(1, "pb\n", 3);
    }
}







