#include "../push_swap.h"

int get_position(int a_num, int *radixs_array)
{
    int i;

    i = 0;
    while (a_num != radixs_array[i])
        i++;
    return (i);
}

void load_array(t_list **a, int *radixs_array, int size)
{
    int i = 0;
    t_list *temp = *a;

    while (i < size)
    {
        radixs_array[i] = temp -> content;
        temp = temp -> next;
        i++;
    }
}

void ft_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void quicksort_array(int *array, int size)
{
    int i = 0;
    while (i < size)
    {
        if (array[i] > array[i + 1])
        {
            ft_swap(&array[i], &array[i + 1]);
            i = 0;
        }
        else 
            i++;
    }
}
