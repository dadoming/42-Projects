#include "../push_swap.h"

int get_position(int a_num, int *radixs_array)
{
    int i;

    i = 0;
    while (a_num != radixs_array[i])
        i++;
    return (i);
}

/*
Get all the positions of the array, 
 making the lowest number become the first one
 and so sucessively
*/
void get_radix_array(int *radixs_array, t_list **a)
{
    int i = 1;
    int smallest;
    int size = ft_lstsize(a);

    smallest = get_smallest_elem(a, size);
    radixs_array[0] = smallest;
    while (size)
    {
        radixs_array[i] = get_next_smallest_elem(smallest, a);
        smallest = radixs_array[i];
        size--;
        i++;
    }
}

int get_smallest_elem(t_list **a, int size)
{
    int smallest;

    smallest = (*a)->content;
    while (size)
    {
        if ((*a)->content < smallest)
            smallest = (*a) -> content;
        (*a) = (*a) -> next;
        size--;
    }
    return (smallest);
}

int get_next_smallest_elem(int smallest, t_list **a)
{
    int size = ft_lstsize(a);
    int new_smallest;

    while (size)
    {
        if((*a)->content > smallest)
            new_smallest = (*a)->content;
        size--;
        (*a) = (*a) ->next;
    }
    return (new_smallest);
}
