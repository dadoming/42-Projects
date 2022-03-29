#include "push_swap.h"

/*

_______________________________



Para o caso 3 combinações:

0  1  2  ||  0  2  1  ||  1  0  2  ||  1  2  0  ||  2  0  1  ||  2  1  0

caso 0       caso 1        caso 2       caso 3      caso 4      caso 5

check         sa            sa           rra         ra          sa

              2  0  1     0  1  2      0  1  2      0  1  2      1  2  0

               ra          check        check       check        rra

              0  1  2                                            0  1  2

              check                                              check



_______________________________




while (lista)

if ( certo )

return lista;

else if ( (1 < 2 && 2 > 3) && (1 > 3 && 3 < 2) )

rra;

else if ( (1 > 2 && 2 < 3) && (3 < 1 && 1 > 2) )

ra;

else

sa;


_______________________________

*/

t_list *swap_three(t_list **a)
{
    int i;

    i = 1;
    while(i <= 3)
    {
        if((*a) -> content < (*a) -> next -> content && (*a) -> next -> content < (*a) -> next -> next -> content && (*a) -> content < (*a) -> next -> next -> content )
            return(*a);
        else if(((*a) -> content < (*a) -> next -> content && (*a) -> next -> content > (*a) -> next -> next -> content) &&
            ((*a) -> content > (*a) -> next -> next -> content && (*a) -> next -> next -> content < (*a) -> next -> content))
                rra(a);
        else if(( (*a) -> content > (*a) -> next -> content && (*a) -> next -> content  < (*a) -> next -> next -> content ) &&
                ( (*a) -> next -> next -> content < (*a) -> content && (*a) -> content > (*a) -> next -> content))
                ra(a);
        else
                sa(a);
        i++;
    }
    return (*a);
}


// t_list *swap_three(t_list *a)
// {
//     int i;

//     i = 1;
//     while(i <= 3)
//     {
//         printf(">>CORREU %dx \n", i);
//         if(a -> content < a -> next -> content && a -> next -> content < a -> next -> next -> content && a -> content < a -> next -> next -> content)
//         {
//             printf("1 -> ");
//             while (a -> next)
//             {
//                 printf("%d ", a -> content);
//                 a = a -> next;
//             }
//             printf("%d\n", a -> content);
//             return(a);
//         }
//         else if((a -> content < a -> next -> content && a -> next -> content > a -> next -> next -> content ) && 
//             (a -> content > a -> next -> next -> content && a -> next -> next -> content < a -> next -> content ))
//                 rra(&a);
//         else if((a -> content > a -> next -> content && a -> next -> content < a -> next -> next -> content ) && 
//                 (a -> next -> next -> content > a -> content && a -> content < a -> next -> content ))
//                 ra(&a);
//         else
//                 sa(&a);
//         i++;
//     }
//     return (a);
// }

