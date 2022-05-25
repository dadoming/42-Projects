/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:23:10 by dadoming          #+#    #+#             */
/*   Updated: 2022/05/25 01:34:53 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lst_is_ordered(t_list *a)
{
    while(a -> content)
    {
        if(a -> next == NULL)
        {
            printf("List is all ordered!\n");
            return (0);
        }
        if(a -> content < a -> next -> content)
            a = a -> next;
        else
            break;
    }
    return(1);
}
------ LEFT TO DEBUG ------
int check_input_string(char **arg)
{
    int i = 0;
    while (arg[i] != '\0')
    {
        if(ft_isdigit(arg[i]) == 0)
        {
            return (-1);
        }
        i++;
    }
    return (0);
}

int check_input(char **argv, int argc)
{
    if(argc == 2)
        return (check_input_string(ft_split(argv[1], ' ')));
    int i = 1;
    while (argv[i] != '\0')
    {
        if(ft_isdigit(argv[i]) == 0)
        {
            return(-1);
        }
        i++;
    }
    return (0);
}
-----------------------------
int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc > 1)
    {
        if(check_input(argv, argc) == -1)
            return (-1);
        a = init_stacks(argc, argv);
        while(1)
        {
            if(lst_is_ordered(a) == 0)
                break ;
            else if(ft_lstsize(a) == 2)
                sort_two(&a);
            else if(ft_lstsize(a) == 3)
                sort_three(&a);
            else if(ft_lstsize(a) == 4)
                sort_four(&a, &b);
            else if(ft_lstsize(a) == 5)
                sort_five(&a, &b);
            // else if(ft_lstsize(a) > 5)
            //     sort_big()
            break ; //  take this off when finished
        }
    }
    
    //  PRINT
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
    
    return(0);
}
