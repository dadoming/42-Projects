/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:20:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/29 19:27:45 by dadoming         ###   ########.fr       */
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
        pa(&a, &b);
        if(ft_lstsize(a) <= 3)
            sort_three(&a);
        if(ft_lstsize(a) <= 5)
            sort_f_f(&a, &b);
    }
    

    /* TEST MOVES:
    sa(&a);
    ra(&a);
    */
    
    /* 
    TEST OUTPUT:
    */
    while (a -> next)
    {
        printf("%d ", a -> content);
        a = a -> next;
    }
    printf("%d\n", a -> content);
    return(0);
}
