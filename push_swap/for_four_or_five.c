#include "push_swap.h"

t_list sort_four(t_list **a, t_list **b)
{
    //else if's porque só quero percorrer as condicoes uma vez
    if((*b) -> content > (*a) -> next -> next -> content)//ultimos 2 numeros num conjunto de 5
    {
        pa(a, b);
        ra(a);
    }
    else if((*a) -> content < (*b) -> content && 
        (*a) -> next -> content < (*b) -> content && 
        (*a) -> next -> next -> content > (*b) -> content)//numero do meio, vai ter sempre o ultimo maior
    {
        rra(a);
        pa(a, b);
        ra(a);
        ra(a);
    }
    else if((*b) -> content > (*a) -> content && 
    (*b) -> content < (*a) -> next -> next -> content) //para o caso dos 2 numeros mais pequenos
    {
        ra(a);
        pa(a, b);
        rra(a);
    }
    else if((*b) -> content < (*a) -> content)//para o caso 1
        pa(a, b);
}

//ENCURTAR AS LINHAS DE CODIGO SIMPLIFICANDO-O
//TENTAR 'CRUZAR' OS IF'S

t_list sort_five(t_list **a, t_list **b)
{
    if((*b) -> content > (*a) -> next -> next -> content &&
        (*b) -> content > (*a) -> next -> next -> next -> content)//5
    {
        pa(a, b);
        ra(a);
    }
    else if((*b) -> content > (*a) -> next -> next -> content &&
        (*b) -> content < (*a) -> next -> next -> next -> content)//4
    {
        rra(a);
        pa(a, b);
        ra(a);
        ra(a);
    }
    else if((*b) -> content > (*a) -> next -> content && 
        (*b) -> content < (*a) -> next -> next -> next -> content)//3
    {
        ra(a);
        ra(a);
        pa(a, b);
        rra(a);
        rra(a);
    }
    else if((*b) -> content > (*a) -> content &&
    (*b) -> content < (*a) -> next -> content)//2
    {
        ra(a);
        pa(a, b);
        rra(a);
    }
    else if((*b) -> content < (*a) -> content)//para o caso 1
        pa(a, b);
}

t_list *sort_f_f(t_list **a, t_list **b)
{
    int i = 0;
    pb(a, b);
    if(ft_lstsize(*a) == 4)
        pb(a, b);
    while ((*a) -> next)
    {
        printf("%d ", (*a) -> content);
        (*a) = (*a) -> next;
    }
    printf("%d\n", (*a) -> content);
    sort_three(a);
    /*
    */
    if(ft_lstsize(*b) == 2)
        sort_four(a, b);
    if(ft_lstsize(*b) == 1)
        sort_five(a, b);
    return(*a);
}