/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:24 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/02 17:33:25 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_big(t_list **a, t_list **b)
{
    head of list = *a;
    int j = 0; //posicao do elemento mais pequeno
    int k = 0; //posicao do segundo elemento mais pequeno
    int hold_value_a = 0;
    int hold_value_b = 0;
    
    int i = 0;
    while(ft_lstsize(a) >= ft_lstsize(b))
    {
        if(*a -> content < *a -> next -> content)
        {
            hold_value_a = *a -> content;
            j = i;
        }
        i++;
        *a = *a -> next;
    }
    
    (a) = head

    i = 0;
    if(hold_value_a > hold_value_b)
    {
        if(j > ft_lstsize(a) / 2)
        {
            while (a-> content)
            {
                rra(a);
                if(j = i)
                {
                    pb();
                    break;
                }
                i++
            }
        }
        else
        {
            while(a -> content)
            {
                
            }
        }
    }
    if(hold_value_b > hold_value_a)
    {
        while (k)
        {
            
        }
    }
}