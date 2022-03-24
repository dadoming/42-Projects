#include "push_swap"

void pa(stack **stack_a, stack **stack_b)
{
    int holder;
    stack *new_head_b;
    
    if(ft_lstsize(*stack_b) > 0)
    {
            holder = (*stack_b) -> content;
            new_head_b = (*stack_b) -> next;
            ft_lstdelone(*stack_b, NULL);
            *stack_b = new_head_b;
            ft_lstadd_front(stack_a, add_new_node(holder));
            write(1, "pa\n", 3);
    /*
            new_head_b = *stack_b;
            *stack_b = new_head_b -> next;
            holder = new_head_b -> content;
            ft_lstdelone(new_head_b, NULL);
            ft_lstadd_front(stack_a, add_new_node(holder));
            write(1, "pa\n", 3);
            */
    }
}

void pb(stack **stack_a, stack **stack_b)
{
    int holder;
    stack *new_head_a;
    
    if(ft_lstsize(*stack_a) > 0)
    {
        
        holder = (*stack_a) -> content;
        new_head_a = (*stack_a) -> next;
        ft_lstdelone(*stack_a, NULL);
        *stack_a = new_head_a;
        ft_lstadd_front(stack_b, add_new_node(holder));
        write(1, "pb\n", 3);
        
/* 
            new_head_a = *stack_a;
            *stack_a = new_head_a -> next;
            holder = new_head_a -> content;
            ft_lstdelone(new_head_a, NULL);
            ft_lstadd_front(stack_b, add_new_node(holder));
            write(1, "pb\n", 3);
  */
    }
}
