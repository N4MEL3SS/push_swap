#include "push_swap.h"

t_stack_val	*get_next_min(t_stack *stack)
{
	t_stack_val		*min;
	t_stack_val		*current;
	int				size;

	min = NULL;
	current = stack->head;
	size = stack->size + 1;
	while (--size)
	{
		if (!min && (current->index == -1))
			min = current;
		if (min && (current->index == -1) && (current->num < min->num))
			min = current;
		current = current->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	t_stack_val	*current;
	int			index;

	index = -1;
	current = get_next_min(stack);
	while (current)
	{
		current->index = ++index;
		current = get_next_min(stack);
	}
}
