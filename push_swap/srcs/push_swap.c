/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadoming <dadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:23:10 by dadoming          #+#    #+#             */
/*   Updated: 2022/06/09 16:12:40 by dadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int lst_is_ordered(t_list *a)
{
    while(a -> content)
    {
        if(a -> next == NULL)
        {
            return (0);
        }
        if(a -> content < a -> next -> content)
            a = a -> next;
        else
            break;
    }
    return(1);
}

void free_list(t_list **a)
{
    t_list	*temp;

	if (!a)
		return ;
	while (*a != NULL)
	{
		temp = (*a)-> next;
		free(*a);
		*a = temp;
	}
	a = NULL;
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    int list_size;

    if (argc < 2)
        return (0);
    if (argc == 2)
        return (0);
    a = NULL;
    b = NULL;
    a = init_stacks(argc, argv);
    list_size = ft_lstsize(a);
    if(!a)
        return(-1);
    if(lst_is_ordered(a) != 0)
    {
        if(list_size == 2)
            sort_two(&a);
        else if(list_size == 3)
            sort_three(&a);
        else if(list_size == 4)
            sort_four(&a, &b);
        else if(list_size == 5)
            sort_five(&a, &b);
        else
            sort_big(&a, &b);
    }
    free_list(&a);
    return(0);
    //  PRINT
    /*
    printf("Stack a: ");
    while (a -> next)
    {
        printf("%d ", a->content);
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
    */
}
