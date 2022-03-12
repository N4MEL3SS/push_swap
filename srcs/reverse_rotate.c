#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	stack->head = stack->head->prev;
}

void	rra(t_stack *stack_a, t_cmds_head *cmds_head)
{
	reverse_rotate(stack_a);
	add_commands(cmds_head, init_cmds_lst(RRA));
}

void	rrb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	reverse_rotate(stack_b);
	add_commands(cmds_head, init_cmds_lst(RRB));
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	rra(stack_a, cmds_head);
	rrb(stack_b, cmds_head);
	add_commands(cmds_head, init_cmds_lst(RRR));
}
