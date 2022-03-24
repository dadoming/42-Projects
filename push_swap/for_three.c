#include "push_swap.h"

/* NOT DONE YET!

Corrigir a forma como o valor sai da funcao find_nodeth e entra
na condicao do if statement

da para inverter o algoritmo com '!' para ser preciso menos 
ciclos de while e demorar menos tempo porque:

ambos os casos em que sao necessarias duas chamadas à lista, sa -> ra e sa -> rra,
o comando sa é o que é executado primeiro.
*/

stack *find_nodeth(stack *a, int nodeth)
{
    int i;
    stack *aux;

    i = 0;
    while(i < nodeth)
    {
        a = a->next;
        i++;
    }
    aux = a;
    printf("%d\n\n", aux -> content);
    return(aux); //testar com um return do a -> next se bem q tenho a certeza q vai dar ao mesmo
}


stack *swap_three(stack *a)
{
    int i;

    i = 1;
    while(i <= 3)
    {
        printf(">>CORREU %dx \n", i);
        if(a < a -> next && a -> next < find_nodeth(a, 2))
        {
            printf("1 -> ");
            while (a -> next)
            {
                printf("%d ", a -> content);
                a = a -> next;
            }
            printf("%d\n", a -> content);
            return (a);
        }
        /* else if((a < a -> next && a -> next > a -> next -> next) && 
            (a > a -> next -> next && a -> next -> next < a -> next))
                rra(&a);
        */
        else if((a > a -> next && a -> next < find_nodeth(a, 2)) && 
                (find_nodeth(a, 2) > a && a < a -> next))
                ra(&a);
        else
                sa(&a);
        i++;
    }
    printf("2 -> ");
    while (a -> next)
    {
        printf("%d ", a -> content);
        a = a -> next;
    }
    printf("%d\n", a -> content);
    return (a);
}

