/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:20:40 by dadoming          #+#    #+#             */
/*   Updated: 2022/03/16 16:42:01 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc init_stacks.c main.c moves_swap.c moves_rotate.c  utils.c

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    stack *a;
    stack *b;

    a = NULL;
    if (argc > 1)
        a = init_stacks(argc, argv);
    //if (argc ) //criar varios meios de para dar sort consoante o valor
    

    /* TEST MOVES:
    
    sa(&a);
    ra(&a);
    
    */

    
    
    /* 
    TEST OUTPUT:
    while (a -> next)
    {
        printf("%d ", a -> content);
        a = a -> next;
    }
    printf("%d\n", a -> content);
    return(0);
    */
    
}
