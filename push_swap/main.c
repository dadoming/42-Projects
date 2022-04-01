/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:20:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/04/01 15:37:13 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc init_stacks.c main.c moves_swap.c moves_rotate.c  utils.c

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc > 1)
    {
        //if(check input errors)
        //if(input 1 numero)
        a = init_stacks(argc, argv);
        if(ft_lstsize(a) <= 3)
            sort_three(&a);
        if(ft_lstsize(a) <= 5)
            sort_less_five(&a, &b);
    }
    /* TEST MOVES:
    
    pa(&a, &b);
    pb(&a, &b);
    pb(&a, &b);

    sa(&a);
    ra(&a);
    */
    printf("Stack a: ");
    while (a -> next)
    {
        printf("%d ", a -> content);
        a = a -> next;
    }
    printf("%d\n", a -> content);
    if(b != NULL)
    {
        printf("Stack b: ");
        while (b -> next)
        {
            printf("%d ", b -> content);
            b = b -> next;
        }
        printf("%d\n", b -> content);
    }
    /* 
    TEST OUTPUT:
    */
    
    
    return(0);
}
