#include "push_swap.h"

void	rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	ra(t_stack *stack_a, t_cmds_head *cmds_head)
{
	rotate(stack_a);
	add_commands(cmds_head, init_cmds_lst(RA));
}

void	rb(t_stack *stack_b, t_cmds_head *cmds_head)
{
	rotate(stack_b);
	add_commands(cmds_head, init_cmds_lst(RB));
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_cmds_head *cmds_head)
{
	ra(stack_a, cmds_head);
	rb(stack_b, cmds_head);
	add_commands(cmds_head, init_cmds_lst(RR));
}
