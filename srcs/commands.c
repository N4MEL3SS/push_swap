#include "../includes/push_swap.h"

void	add_commands(t_cmds_head *cmds_head, t_cmds_lst *lst)
{
	if (!cmds_head->head)
	{
		cmds_head->head = lst;
		cmds_head->tail = lst;
	}
	else
		cmds_head->tail->next = lst;
	cmds_head->size++;
}

t_cmds_head	*cmds(t_stack *stack_a, int (*markup)(t_stack_val *))
{
	t_cmds_head	*cmds_head;
	t_stack		*stack_b;

	stack_b = init_stack();
	cmds_head = init_cmds();
	commands_a(stack_a, stack_b, cmds_head, markup);
	free_stack(stack_b);
	return (cmds_head);
}
