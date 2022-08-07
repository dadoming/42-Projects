#include "../push_swap.h"

int ft_is_sorted(t_list **stack)
{
    int i;

    i = 0;
    while((*stack) -> next)
    {
        printf("sort %d: %d\n", i, (*stack) -> content);
        if((*stack) -> content > (*stack) -> next -> content) //break if notices not sorted
            break ;
        else if((*stack) -> content < (*stack) -> next -> content)
            i++;
        if(ft_lstsize(*stack) == i) //compares all
            return (1);
        *stack = (*stack) -> next;
    }
    return (0);
}