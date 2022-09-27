#include "../push_swap.h"

void sort(t_list **a, t_list **b)
{
    int list_size;
    
    list_size = ft_lstsize(*a);
    if(list_size == 2)
        sort_two(a);
    else if(list_size == 3)
        sort_three(a);
    else if(list_size == 4)
        sort_four(a, b);
    else if(list_size == 5)
        sort_five(a, b);
    else
        sort_big(a, b);
}