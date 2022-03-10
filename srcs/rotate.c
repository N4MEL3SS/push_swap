#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}
