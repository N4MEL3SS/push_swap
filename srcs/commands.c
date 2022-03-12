#include "push_swap.h"

void		align_a(t_stack *stack_a, t_cmds_head *cmds_head)
{
	t_stack_val		*current;
	int 			ra_size;
	int 			rra_size;

	if (stack_a && stack_a->head)
	{
		ra_size = 0;
		current = stack_a->head;
		while (current->index != 0 && ++ra_size)
			current = current->next;
		rra_size = 0;
		current = stack_a->head;
		while (current->index != 0  && ++rra_size)
			current = current->prev;
		while (stack_a->head->index != 0 && ra_size < rra_size)
			ra(stack_a, cmds_head);
		while (stack_a->head->index != 0 && ra_size >= rra_size)
			rra(stack_a, cmds_head);
	}
}

void	add_commands(t_cmds_head *cmds_head, t_cmds_lst *lst)
{
	if (!cmds_head->head)
	{
		cmds_head->head = lst;
		cmds_head->tail = lst;
	}
	else
	{
		cmds_head->tail->next = lst;
		cmds_head->tail = lst;
	}
	cmds_head->size++;
}

t_cmds_head	*commands(t_stack *stack_a, int (*markup)(t_stack_val *))
{
	t_cmds_head	*cmds_head;
	t_stack		*stack_b;

	stack_b = init_stack();
	cmds_head = init_cmds();
	commands_a(stack_a, stack_b, cmds_head, markup);
	commands_b(stack_a, stack_b, cmds_head);
	align_a(stack_a, cmds_head);
	free_stack(stack_b);
	return (cmds_head);
}
