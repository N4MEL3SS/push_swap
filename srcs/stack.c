#include "../includes/stack.h"

t_stack	*stack_init(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->value = num;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_create(int num, t_stack *prev)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->value = num;
	stack->prev = prev;
	stack->next = NULL;
	stack->prev->next = stack;
	return (stack);
}
