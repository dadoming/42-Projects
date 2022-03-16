#include "push_swap.h"

static void rotate(stack **head_of_stack)
{
    stack *top_node;
    stack *temp;

    if(*head_of_stack && ft_lstsize(*head_of_stack) > 1)
    top_node = *head_of_stack;
    temp = top_node;
    *head_of_stack = top_node -> next;
    while (temp -> next)
        temp = temp -> next;
    temp -> next = top_node;
    top_node -> next = NULL;
}

void ra(stack **stack_a)
{
    if(*stack_a)
    {
        rotate (stack_a);
        write(1, "ra\n", 3);
    }
}

void rb(stack **stack_b)
{
    if(*stack_b)
    {
        rotate (stack_b);
        write(1, "rb\n", 3);
    }
}

void rr(stack **stack_a, stack **stack_b)
{
    rotate (stack_a);
    rotate (stack_b);
    write(1, "rr\n", 3);
}