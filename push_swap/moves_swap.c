#include "push_swap.h"

/*
Unlike global functions in C, access to static functions is restricted to the 
file where they are declared. Therefore, when we want to restrict access to 
functions, we make them static. Another reason for making functions static can 
be reuse of the same function name in other files.
*/

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
        write (1, "sa\n", 3);
    }
}

void sb(t_list **stack_b)
{
    if(ft_lstsize(*stack_b) > 1)
    {
        swap (stack_b);
        write (1, "sb\n", 3);
    }
}

void ss(t_list **stack_a, t_list **stack_b)
{
    if(ft_lstsize(*stack_a) > 1)
        swap (stack_a);
    if(ft_lstsize(*stack_b) > 1)
        swap (stack_b);
    write(1, "ss\n", 3);
}