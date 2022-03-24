#include "push_swap.h"

static void rev_rotate(stack **head_of_stack)
{
    stack *temp;
    stack *bot;

    if(ft_lstsize(*head_of_stack) > 1)
    {
        temp = *head_of_stack;
        bot = ft_lstlast(*head_of_stack);
        while (temp -> next -> next)
            temp = temp -> next;
        temp -> next = NULL;
        bot -> next = *head_of_stack;
        *head_of_stack = bot;
    }
}

void rra(stack **stack_a)
{
    if(ft_lstsize(*stack_a) > 1)
    {
        rev_rotate(stack_a);
        write(1, "rra\n", 4);
    }
}

void rrb(stack **stack_b)
{
    if(ft_lstsize(*stack_b) > 1)
    {
        rev_rotate(stack_b);
        write(1, "rrb\n", 4);
    }
}

void rrr(stack **stack_a, stack **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    write(1, "rrr\n", 4);
}
