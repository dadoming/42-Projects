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

#include "../push_swap.h"

void radix(t_list **a, t_list **b)
{
    int size = ft_lstsize(*a);
    int max_num = size - 1; // the biggest number in stack a will be size - 1
    int max_bits = 0;

    // Loops through the operation until reaches condition to get the
    // maximum number of bits that need to be parsed right until all 00000000
    // to get the amount of times that the next loop will loop
    // For example: 13>>0 = 13
    //              13>>1 = 6
    //              13>>2 = 3
    //              13>>3 = 1
    //              13>>4 = 0
    while (max_num >> max_bits != 0)
        ++max_bits;
    int i = 0;
    int j = 0;
    while (i <= max_bits)
    {
        while (j++ < size)
        {
            int num = (*a)->content;
            if(((num >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
        }
        j = 0;
        i++;
        while(ft_lstsize(*b) > 0)
        {
            pa(a, b);
        }
    }
}

void sort_big(t_list **a, t_list **b)
{
    radix(a, b);
}
