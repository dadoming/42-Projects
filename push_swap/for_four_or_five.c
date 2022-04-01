#include "push_swap.h"
/*
void sort_four(t_list **a, t_list **b)
{
    // if(ft_is_sorted(a))
    //     return ;
    //else if's porque só quero percorrer as condicoes uma vez
    
    
    if((*b) -> content > (*a) -> next -> content &&
    (*b) -> content > (*a) ->content )//ultimos 2 numeros num conjunto de 5
    {
        if((*b) -> next -> content < (*b) -> content &&
        (*b) -> next -> content > (*a) -> next -> content)
        {
            pa(a, b);
            rra(a);
            if((*a) -> content > (*a) -> next -> next -> next -> content)
                pa(a, b);
            else
            {
                sa(a);
                pa(a, b);
            }
            ra(a);
            ra(a);
            ra(a);
        }
        else
        {
            pa(a, b);
            ra(a);
        }
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

void sort_five(t_list **a, t_list **b)
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
    pb(a, b);
    if(ft_lstsize(*a) == 4)
        pb(a, b);
    sort_three(a);
    if(ft_lstsize(*b) == 2)
        sort_four(a, b);
    if(ft_lstsize(*b) == 1)
        sort_five(a, b);
    return(*a);
}
*/





void put_on_top(t_list **a, t_list **b)
{
    if ((*b) -> content > (*a) -> content &&
            (*b) -> content > (*a) -> next -> next -> content)
        pa(a, b);
    else if((*b) -> content > (*a) -> content &&
        (*b) -> content > (*a) -> next -> content)
    {
        rra(a);
        pa(a, b);
    }
    else if((*b) -> content > (*a) -> content &&
        (*b) -> content < (*a) -> next -> content)
    {
        ra(a);
        pa(a, b);
    }
    else if((*b) -> content > (*a) -> content)
    {
        ra(a);
        pa(a, b);
    }
    if((*b) != NULL) //if fits one more on top
    {
        if((*b) -> content < (*a) -> content)
        {
            pa(a, b);
            sa(a);
        }
    }
}

void put_one_more(t_list **a, t_list **b)
{
    if()
}

void last_biggest(t_list **a)
{
    if(ft_lstsize((*a)) == 4)
    {
        if((*a) -> content > (*a) -> next -> content &&
        (*a) -> content > (*a) -> next -> next -> next -> content)
            ra(a);
    }
    if(ft_lstsize((*a)) == 5)
    {
        if((*a) -> content > (*a) -> next -> content &&
        (*a) -> content > (*a) -> next -> next -> next -> next -> content)
            ra(a);
    }
}

void low_sorter(t_list **a, t_list **b)
{
    put_on_top(a, b);
    if(b != NULL)
    {
        put_one_more(a, b);
    }

    last_biggest(a);
}


t_list *sort_less_five(t_list **a, t_list **b)
{
    pb(a, b);
    if(ft_lstsize(*a) == 4)
        pb(a, b);
    sort_three(a);
    low_sorter(a, b);
    return(*a);
}

/*
t_list *sort_f_f(t_list **a, t_list **b)
{
    pb(a, b);
    if(ft_lstsize(*a) == 4)
        pb(a, b);
    sort_three(a);
    if(ft_lstsize(*b) == 2)
        sort_four(a, b);
    if(ft_lstsize(*b) == 1)
        sort_five(a, b);
    return(*a);
}
*/