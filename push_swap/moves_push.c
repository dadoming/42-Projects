#include "push_swap"

/*
apenas dar 'push' e ignorar a perda da lista sendo que nao ha mais nodes
*/
static void push(stack **fill_stack, stack **take_stack)
{
    stack *head_stack;
    stack *head_node_to_change;

    head_of_stack = *fill_stack;
    head_node_to_change = *take_stack;
    
}

/*
para dar 'push' ao node e atribuir o head link ao next node de forma
a nao perder a lista
*/
void push_and_link(stack **fill_stack, stack **take_stack)
{
    stack *head_stack;
    stack *head_node_to_change;

    head_of_stack = *fill_stack;
    head_node_to_change = *take_stack;
    
}



void pa(stack **stack_a, stack **stack_b)
{
    if(ft_lstsize(stack_b) > 1)
    {
        push_and_link(stack_a, stack_b);
        write(1, "pa\n", 3);
    }
    if(ft_lstsize(stack_b) = 1)
    {
        push(stack_a, stack_b);
        write(1, "pa\n", 3);
    }
}

void pb(stack **stack_a, stack **stack_b)
{
    if(ft_lstsize(stack_a) > 1)
    {
        push_and_link(stack_b, stack_a);
        write(1, "pb\n", 3);
    }
    if(ft_lstsize(stack_a) = 1)
    {
        push(stack_b, stack_a);
        write(1, "pb\n", 3);
    }
}
