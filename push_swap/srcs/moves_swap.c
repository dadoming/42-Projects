/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:34:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/24 19:35:07 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_list **head_of_stack)
{
    t_list *first;
    t_list *second;
    t_list *third;

    first = *head_of_stack;
    second = (*head_of_stack) -> next;
    third = second -> next;
    *head_of_stack = second; 
    second -> next = first;
    first ->next = third;
}

void sa(t_list **stack_a)
{
    if(ft_lstsize(*stack_a) > 1)
    {
        swap (stack_a);
        print_msg("sa", 0);
    }
}

void sb(t_list **stack_b)
{
    if(ft_lstsize(*stack_b) > 1)
    {
        swap (stack_b);
        print_msg("sb", 0);
    }
}

void ss(t_list **stack_a, t_list **stack_b)
{
    if(ft_lstsize(*stack_a) > 1)
        swap (stack_a);
    if(ft_lstsize(*stack_b) > 1)
        swap (stack_b);
    print_msg("ss", 0);
}