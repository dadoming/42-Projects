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
int get_radix_array(int *radixs_array, t_list **a)
{

}